#include "fiveTask.h"

using namespace Utils;

//https://ru.stackoverflow.com/questions/607542/%D0%9F%D0%B5%D1%80%D0%B5%D0%B4%D0%B0%D1%87%D0%B0-%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B5%D0%B9-%D0%B2-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8E-c

namespace TaskFive {
    // region контейнер односвязанного списка
    struct Node {
        // region Информационная часть узла (полезные данные)
        int degree; // степень
        double index; // коэффициент (real)
        // endregion

        Node *next; // связь
        Node(int _degree, double _index) : degree(_degree), index(_index) {}
    };

    // endregion

    // region односвязный список
    struct list {
        Node *first;
        Node *last;

        list() : first(nullptr), last(nullptr) {}

        //функция проверки наличия узлов в списке;
        bool is_empty() {
            return first == nullptr;
        }

        //Добавление узла в конец списка
        void push_back(int degree, double index) {
            Node *p = new Node(degree, index);
            if (is_empty()) {
                first = p;
                last = p;
                return;
            }
            last->next = p;
            last = p;
        }

        void push_front(int degree, double index) {
            Node *p = new Node(degree, index);
            if (is_empty()) {
                first = p;
                last = p;
                return;
            }
            p->next = first;
            first = p;
        }

        void print() {
            if (is_empty()) return;
            Node *node = first;

            cout << "Многочлен: ";
            while (node) {
                cout << node->index << (node->degree > 0 ? "*x^" + std::to_string(node->degree) : "") << " + ";
                node = node->next;
            }
            cout << "\b\b\b" << endl;
        }

        void remove_first() {
            Node *removeEl = first;
            first = first->next;
            delete removeEl;
        }

        void remove_last() {
            Node *preLast = first;
            while (preLast->next && (preLast->next->degree != last->degree || preLast->next->index != last->index))
                preLast = preLast->next;
            preLast->next = nullptr;
            Node *removeEl = last;
            last = preLast;
            delete removeEl;
        }

        void remove(int degree, double index) {
            if (is_empty()) return;
            if (first->degree == degree && first->index == index) {
                remove_first();
                return;
            } else if (last->degree == degree && last->index == index) {
                remove_last();
                return;
            }
            Node *slow = first;
            Node *fast = first->next;
            while (fast && (fast->degree != degree || fast->index != index)) {
                fast = fast->next;
                slow = slow->next;
            }
            if (!fast) {
                cout << "This element does not exist!" << endl;
                return;
            }
            slow->next = fast->next;
            delete fast;
        }

        list* find(int degree) {
            list *result = new list();
            Node *p = first;
            while (p) {
                if(p->degree == degree) {
                    result->push_back(p->degree, p->index);
                }
                p = p->next;
            }
            return result;
        }

        double sumIndex() {
            double result = 0;
            Node *p = first;
            while (p) {
                result += p->index;
                p = p->next;
            }
            return result;
        }

        int getMaxDegree() {
            int maxDegree = 0;
            Node *p = first;
            while (p) {
                if(p->degree > maxDegree) {
                    maxDegree = p->degree;
                }
                p = p->next;
            }
            return maxDegree;
        }

        double getResultGorner(int x) {
            int degree = getMaxDegree();
            double result = 0;
            for(int i = degree; i >= 0; i--) {
                list *listByDegree = find(i);
                double sumIndex = listByDegree->sumIndex();
                if (result == 0) {
                    result = sumIndex;
                } else {
                    result = x * result + sumIndex;
                }
                delete listByDegree;
            }
            return result;
        }
    };
    // endregion

    std::string FiveTask::getName() {
        return "Практическая работа № 1.5";
    }

    string FiveTask::getId() {
        return "1.5";
    }

    int FiveTask::execute() {
        cout << "Запуск задачи:\n>> 1 - Создания нового списка вручную\n>> 2 - Использования уже готового списка для тестирования\n>> Выберите режим работы: ";
        int workMode = Utils::getInput<int>();

        list *l = new list();
        switch (workMode) {
            case 1: { //а) создания нового списка вручную
                cout << "Введите размер многочлена: ";
                int n = getInput<int>();
                cout << "Введите многочлен:" << endl;
                double index;
                int degree;
                for (int i = 0; i < n; i++) {
                    cout << i + 1 << ") Коэффициент = ";
                    index = getInput<double>();
                    cout << i + 1 << ") Степень x = ";
                    degree = getInput<int>();
                    l->push_back(degree, index);
                }
            }
            break;

            case 2: {// б) использования уже готового списка для тестирования заданий
                // 2*x^4 + 7*x^3 + -2*x^2 + -13*x^1 + 6
                // при x(1) = 0
                l->push_back(4, 2);
                l->push_back(3, 7);
                l->push_back(2, -2);
                l->push_back(1, -13);
                l->push_back(0, 6);
            }
            break;

            default:
                cout << "Выбран некорректный режим работы программы!" << endl;
                return EXIT_FAILURE;
        }

        l->print();
        cout << "x = ";
        int x = getInput<int>();
        cout << "Значение многочлена: " << l->getResultGorner(x) << endl;
	    return EXIT_SUCCESS;
    }
}