#include "six2Task.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <map>

#include <vector>
#include <algorithm>

#include <queue>
#include <unordered_map>


namespace six2Task {

	std::string string_to_hex(const std::string& in) {
		std::stringstream ss;

		ss << std::hex << std::setfill('0');
		for (size_t i = 0; in.length() > i; ++i) {
			ss << std::setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(in[i]));
		}

		return ss.str();
	}

	namespace shenon {
		struct node {
			string sym; // Хранение символа
			float pro; // Вероятность появления

			int arr[50]; // Биты
			int top; // Кол-во бит кодирования
		}p[50]; // Таблица символов

		typedef struct node node;

		// Сжатие методом Шеннона–Фано
		void shannon(int l, int h) {
			float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;

			int i, d, k, j;

			if ((l+1) == h or l==h or l>h) { // Есди вероятности появления в ветвях равны
				if (l == h or l > h) {
					return;
				}

				p[h].arr[++(p[h].top)] = 0; // Всем выше присваиваю +0 в код
				p[l].arr[++(p[l].top)] = 1; // всем ниже присваиваю +1 в код
				return;
			} else { // иначе считаем вероятности и находим середину
				for (i = l; i <= h - 1; i++) {
					pack1 = pack1 + p[i].pro;
				}

				pack2 = pack2 + p[h].pro;
				diff1 = pack1 - pack2;
				if (diff1 < 0) {
					diff1 = diff1 * -1;
				}

				j = 2;
				while (j != h-l+1) {
					k = h - j;
					pack1 = pack2 = 0;
					for (i = l; i <= k; i++) {
						pack1 = pack1 + p[i].pro;
					}
					for (i = h; i > k; i--) {
						pack2 = pack2 + p[i].pro;
					}
					diff2 = pack1 - pack2;
					if (diff2 < 0) {
						diff2 = diff2 * -1;
					}

					if (diff2 >= diff1)
						break;

					diff1 = diff2;
					j++;
				}
				k++;

				for (i = l; i <= k; i++) {
					p[i].arr[++(p[i].top)] = 1;
				}
				for (i = k + 1; i <= h; i++) {
					p[i].arr[++(p[i].top)] = 0;
				}

				shannon(l, k); //рекурсивно вызываем её саму же
				shannon(k + 1, h);
			}
		}

		// Функция для сортировки символов на основе их вероятности или частоты
		void sortByProbability(int n, node p[]) {
			int i, j;
			node temp;
			for (j = 1; j <= n - 1; j++) {
				for (i = 0; i < n - 1; i++) {
					if ((p[i].pro) > (p[i + 1].pro)) {
						temp.pro = p[i].pro;
						temp.sym = p[i].sym;

						p[i].pro = p[i + 1].pro;
						p[i].sym = p[i + 1].sym;

						p[i + 1].pro = temp.pro;
						p[i + 1].sym = temp.sym;
					}
				}
			}
		}

		// Вывод данных об уникалных символах
		void display(int n, node p[], int sentenceLength) {
			int i, j;
			cout << "\n\tСимвол\tВероятность\tКод";
			for (i = 0; i < n; i++) {
				cout << "\n\t" << p[i].sym << "\t\t" << p[i].pro << "\t";

				for (j = 0; j <= p[i].top; j++)
					cout << p[i].arr[j];
			}

			//Подсчет эффективности сжатия
			int result = 0;
			int count;
			for (i = n - 1; i >= 0; i--) {
				count = 0;
				for (j = 0; j <= p[i].top; j++) {
					count++;
				}
				result += count * p[i].pro * sentenceLength;
			}

			cout << "\n" << "Закодированное предложение занимает: " << result << " бит.";
			cout << "\n" << "Коэффициент сжатия: " << sentenceLength * 8.0 / result;
			cout << "\n" << "Коэффициент сжатия архиватора ZIP: " << 171.0/121.0 << "\n";
		}

		// Конвертация фразы в сжатый код(закодированной последовательности)
		string encode(string sentence, int k) {
			string encodeStrResult;
			string outputStr = "";

			for(std::string::iterator it = sentence.begin(); it != sentence.end(); it++) {
				string s;

				char c = *it;
				if((int)c < 0) {
					std::ostringstream os;
					os << c;

					int iteratorBytes = 0;
					while((int)*(it + 1) < 0) {
						if(iteratorBytes > 1 && string_to_hex(string(1, *(it + 1)))[0] == 'd') {
							break;
						}

						it++;
						os << *it;

						string tempStr = os.str();
						string hexTempStr = string_to_hex(tempStr);
						if(tempStr.length() == 2 && hexTempStr[0] == 'd') {
							break;
						}
						iteratorBytes++;
					}

					s = os.str();
				} else {
					s = string(1, c);
				}

				string v = "";
				for (int l = 0; l < k; l++) {
					if (p[l].sym == s) { // сравнение с уникальным символом на дереве
						for (int j = 0; j <= p[l].top; j++) {
							v += to_string(p[l].arr[j]); // добавление соответствующего кода в строку
						}
						encodeStrResult += v;
						outputStr += v +" ";
					}
				}
			}
			cout << endl << "\nЗакодированная фраза: " << outputStr << endl;
			return encodeStrResult;
		}

		// Декодирование сжатого кода
		void decode(string code, node p[], int k) {
			cout << "\nДекодированная -> \t";

			string ch = "";
			string n = "";
			for(int i = 0; i < code.size(); i++) { // проверяем код каждого символа, начинаем с самого частого
				ch += code[i];

				for (int l = 0; l < k; l++) {
					string v = "";
					for (int j = 0; j <= p[l].top; j++) {
						v += to_string(p[l].arr[j]);
					}

					if (ch == v) { // cравнение с уникальным символом на дереве
						n = p[l].sym;
						cout << n; // добавление соответствующего кода в stdout

						ch = "";
					}
				}

			}
			cout << endl;
		}

		void execute() {
			int  i, j;
			string sentence;
			float total = 0;
			string ch;

			cout << "Введите строку\t:";
			getline(cin, sentence);
			int sentenceLength = 0;

			for (i = 0; i < sentence.size(); i++) {
				ch = sentence[i];
			}

			int sum = 0;
			int k = 0;

			std::unordered_map<string, int> chars;

			for(std::string::iterator it = sentence.begin(); it != sentence.end(); it++) {
				char c = *it;
				if((int)c < 0) {
					std::ostringstream os;
					os << c;

					int iteratorBytes = 0;
					while((int)*(it + 1) < 0) {
						if(iteratorBytes > 1 && string_to_hex(string(1, *(it + 1)))[0] == 'd') {
							break;
						}

						it++;
						os << *it;

						string tempStr = os.str();
						string hexTempStr = string_to_hex(tempStr);
						if(tempStr.length() == 2 && hexTempStr[0] == 'd') {
							break;
						}
						iteratorBytes++;
					}

					++chars[os.str()];
					sentenceLength++;
				} else {
					++chars[string(1, c)];
					sentenceLength++;
					//cout << "(" << string_to_hex(string(1,c)) << "): " << c << endl;
				}
			}

			for (const auto& l : chars) {
				sum += l.second;
				p[k].sym = l.first;
				k++;
			}

			float x[50] = { 0 };
			i = 0;
			for (const auto& l : chars) {
				cout << "\nВероятность символа " << p[i].sym << " : ";
				x[i] = (float)l.second / (float)sum;
				cout << (float)x[i] << " | (кол-во / общее кол-во) " << l.second << " / " << sum;

				p[i].pro = x[i];
				total += p[i].pro;
				i++;
			}

			cout << "total = " << total << endl;
			p[i].pro = 1 - total;

			//вызов функции сортировки символов на основе их вероятности
			sortByProbability(k, p);

			for (i = 0; i < k; i++) {
				p[i].top = -1;
			}

			shannon(0, k - 1);
			string cod = encode(sentence, k); // кодирование фразы

			display(k, p, sentenceLength);
			cout << endl;

			decode(cod, p, k);
			cout << "\nСжатие: -> " << 100 - (((float)cod.size() * 100) / ((float)sentence.size() * 8)) << "%\n";
		}
	}

	namespace huffman {

		// узел дерева
		struct Node {
			string ch;
			int freq;
			Node* left, * right; //левая и правая ветви
		};

		// Функция добавления нового узла на дерево
		Node* getNode(string ch, int freq, Node* left, Node* right) {
			Node* node = new Node();
			node->ch = ch;
			node->freq = freq;
			node->left = left;
			node->right = right;

			return node;
		}

		// Функция сравнения узлов для сортировки
		struct comp {
			bool operator()(Node* l, Node* r) {
				// узел с большим приоритетот имеет меньшую частоту
				return l->freq > r->freq;
			}
		};

		//Функция кодировки
		// обход дерева Хаффмана и хранение кодов в map
		void encode(Node* root, string str, unordered_map<string, string>& huffmanCode) {
			if (root == nullptr)
				return;

			// если найден лист
			if (!root->left && !root->right) {
				huffmanCode[root->ch] = str;
			}

			encode(root->left, str + "0", huffmanCode);
			encode(root->right, str + "1", huffmanCode);
		}

		// Обход Н-Дерева и декодирование зашифрованного предложения
		void decode(Node* root, int& index, string str) {
			if (root == nullptr) {
				return;
			}

			// найден листовой узел
			if (!root->left && !root->right) {
				cout << root->ch;
				return;
			}
			index++;

			if (str[index] == '0') {
				decode(root->left, index, str);
			}
			else {
				decode(root->right, index, str);
			}
		}

		// Функция построения H-дерева и декодирования введенного сообщения
		void buildHuffmanTree(string text) {
			// Считает частоту появления каждого символа
			// и сохраняет его в map
			unordered_map<string, int> freq;
			for(std::string::iterator it = text.begin(); it != text.end(); it++) {
				char c = *it;
				if((int)c < 0) {
					std::ostringstream os;
					os << c;

					int iteratorBytes = 0;
					while((int)*(it + 1) < 0) {
						if(iteratorBytes > 1 && string_to_hex(string(1, *(it + 1)))[0] == 'd') {
							break;
						}

						it++;
						os << *it;

						string tempStr = os.str();
						string hexTempStr = string_to_hex(tempStr);
						if(tempStr.length() == 2 && hexTempStr[0] == 'd') {
							break;
						}
						iteratorBytes++;
					}

					++freq[os.str()];
				} else {
					++freq[string(1, c)];
				}
			}

			// Создаем очередь с приоритетом для хранения текущих узлов Н-дерева
			// приоритет задает функция сравнения comp
			priority_queue<Node*, vector<Node*>, comp> pq;

			// Создаем листовой узел для каждого символа и кладем его в очередь
			for (auto pair : freq) {
				pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
			}

			// выполняется пока количество узлов в очереди больше одного
			while (pq.size() != 1) {
				// удаляем два узла с наибольшим приоритетом (наименьшей частотой)
				Node* left = pq.top(); pq.pop();
				Node* right = pq.top();	pq.pop();

				// Создаем внутренний узел с двумя этими узлами как с потомками
				// и частотой равной сумме их частот

				// Добавляем узел в очередь
				int sum = left->freq + right->freq;
				pq.push(getNode("\0", sum, left, right));
			}

			// root хранит указатель на корень Н-дерева
			Node* root = pq.top();

			// обходим Н-дерево и сохраняем коды в map
			unordered_map<string, string> huffmanCode;
			encode(root, "", huffmanCode);

			// также выводим их
			cout << "Коды Хафманна:\n" << '\n';
			for (auto pair : huffmanCode) {
				cout << pair.first << " " << pair.second << '\n';
			}
			cout << "\nИсходный текст :\n" << text << '\n';

			// вывод закодированного текста
			string str = "";
			cout << "\nЗакодированное сообщение:\n";

			for(std::string::iterator it = text.begin(); it != text.end(); it++) {
				char c = *it;
				if((int)c < 0) {
					std::ostringstream os;
					os << c;

					int iteratorBytes = 0;
					while((int)*(it + 1) < 0) {
						if(iteratorBytes > 1 && string_to_hex(string(1, *(it + 1)))[0] == 'd') {
							break;
						}

						it++;
						os << *it;

						string tempStr = os.str();
						string hexTempStr = string_to_hex(tempStr);
						if(tempStr.length() == 2 && hexTempStr[0] == 'd') {
							break;
						}
						iteratorBytes++;
					}

					str += huffmanCode[os.str()];
					cout << huffmanCode[os.str()] << "  ";
				} else {
					str += huffmanCode[string(1, c)];
					cout << huffmanCode[string(1, c)] << "  ";
				}
			}

			cout << "\nКоличество знаков в закодированном сообщении:\n"<<str.length() << '\n';
			cout << "\nКоэффициент сжатия:\n" << text.length() * 8.0 / str.length() << '\n';

			// обход Н-дерева снова и декодирование зашифрованного текста
			int index = -1;
			cout << "\nРасшифрованное сообщение: \n";
			while (index < (int)str.size() - 2) {
				decode(root, index, str);
			}
			cout << "\nСжатие: -> " << 100 - (((float)str.size() * 100) / ((float)text.size() * 8)) << "%\n";
			cout << endl;
		}

		void execute() {
			string sentence;

			cout << "Введите строку\t:";
			getline(cin, sentence);
			string sentenceCopy = sentence;
			cout << sentence << endl;
			buildHuffmanTree(sentence);
		}

	}

	typedef std::pair<std::string, int> pair;

	std::string Six2Task::getName(){
		return "Практическая работа № 2.6";
	}

	std::string Six2Task::getId(){
		return "2.6";
	}

	void dumpCountSymbols() {
		cout << "Введите строку для частотного поиска: \n";
		string input;

		std::getline(std::cin, input);

		unsigned int sizeText = 0;
		map<string, int> freqDict;
		for(std::string::iterator it = input.begin(); it != input.end(); it++) {
			char c = *it;
			string result = "";
			if((int)c < 0) {
				std::ostringstream os;
				os << c;

				int iteratorBytes = 0;
				while((int)*(it + 1) < 0) {
					if(iteratorBytes > 1 && string_to_hex(string(1, *(it + 1)))[0] == 'd') {
						break;
					}

					it++;
					os << *it;

					string tempStr = os.str();
					string hexTempStr = string_to_hex(tempStr);
					if(tempStr.length() == 2 && hexTempStr[0] == 'd') {
						break;
					}
					iteratorBytes++;
				}

				result = os.str();
				//cout << "(" << string_to_hex(result) << "): " << result << endl;
			} else {
				result = string(1, c);
				//cout << "(" << string_to_hex(string(1,c)) << "): " << c << endl;
			}
			if(freqDict.find(result) != freqDict.end()) {
				freqDict[result]++;
			} else {
				freqDict[result] = 1;
			}
			sizeText++;
		}

		//cout << "size Text: " << sizeText << endl;
		std::vector<pair> vec;

		std::copy(freqDict.begin(),
		          freqDict.end(),
		          std::back_inserter<std::vector<pair>>(vec));

		std::sort(vec.begin(), vec.end(),
		          [](const pair &l, const pair &r)
		          {
			          if (l.second != r.second) {
				          return l.second > r.second;
			          }

			          return l.first > r.first;
		          });

		int sum = 0;
		for (auto const &pair: vec) {
			std::string key = pair.first;
			int value = pair.second;
			sum += value;
			std::cout << key << " -> ("<< string_to_hex(key) << ") -> " << value << " -> " << std::setprecision(2) << value * 100.0 / sizeText << "%" << std::endl;
		}
		cout << "Кол-во символов: " << sum << endl;
	}

	int Six2Task::execute(){
		cout << "=-=-=КОМАНДЫ=-=-=:\n>> 1 - вывести количество символов в тексте(dump)\n>> 2 - Шеннон фано\n>> 3 - Хаффман\n>> 4 - ??\n>> 5 - ??\n";
		cout << ">> Введите ID команды: ";
		int cmdSelected = Utils::getInput<int>();
		switch (cmdSelected) {
			case 1:
				dumpCountSymbols();
				break;

			case 2:
				shenon::execute();
				break;

			case 3:
				huffman::execute();
				break;

			default:
				cout << "Выбранная команда не найдена!" << endl;
		}
		return EXIT_SUCCESS;
	}
}
