#include "five2Task.h"

#include <algorithm>
#include <vector>

#define VERTEX_COUNT 100000

namespace five2Task {

	std::string Five2Task::getName(){
		return "Практическая работа № 2.5";
	}

	std::string Five2Task::getId(){
		return "2.5";
	}

	// Тип представления ребер
	struct edge {
		//начало, конец, вес
		int a, b, len;

		bool operator < (const edge& other) const {
			return len < other.len;
		}
	};

	// region система не пересекающихся множеств (DSU)
	int parent[VERTEX_COUNT];
	int groupSize[VERTEX_COUNT];
	// endregion

	void init_dsu() {
		for (int i = 0; i < VERTEX_COUNT; i++) {
			parent[i] = i;
			groupSize[i] = 1;
		}
	}

	/**
	 *
	 *
	 * @param v
	 * @return
	 */
	int findLeader(int i) {
		if (parent[i] == i){
			return i;
		} else {
			//На выходе из рекурсии переподвешиваем i
			parent[i] = findLeader(parent[i]);
			return parent[i];
		}
	}

	bool sameGroup(int x, int y) {
		int leader1 = findLeader(x);
		int leader2 = findLeader(y);

		return leader1 == leader2;
	}

	/**
	 * Проверка находится ли вершины в одной компоненте
	 *
	 * @param x
	 * @param y
	 * @return
	 */
	bool mergeGroups(int x, int y) {
		if(sameGroup(x, y)) return false;

		int leader1 = findLeader(x);
		int leader2 = findLeader(y);
		if (groupSize[x] < groupSize[y]) {
			parent[leader1] = leader2;
			groupSize[leader2] += groupSize[leader1];
		}else if (groupSize[leader2] < groupSize[leader1]) {
			parent[leader2] = leader1; // родитель теперь leader1 у leader2
			groupSize[leader1] += groupSize[leader2];
		} else {
			parent[leader1] = leader2;
			groupSize[leader2]++;
		}
		return true;
	}

	int getSize(int x) {
		int leader = findLeader(x);
		return groupSize[leader];
	}

	/*
		countEdge = 8
	    5 1 10
	    5 3 7
	    5 4 11
	    5 2 6
	    4 2 3
	    4 3 4
	    3 1 2
	    2 1 1
	*/
	int Five2Task::execute(){
		vector<edge> edges; // края
		vector<edge> news;
		int countEdge;
		cout << "Количество граней:" << endl;
		cin >> countEdge;
		cout << "Грани (начало, конец, вес):" << endl;

		// Ввод edges...
		for (int i = 0; i < countEdge; i++) {
			edge e;
			cin >> e.a >> e.b >> e.len;

			edges.push_back(e);
		}

		//Вначале мы производим сортировку рёбер по возрастанию по их весам.
		sort(edges.begin(), edges.end());
		cout << endl << "Отсортированный граф" << endl;
		for (int i = 0; i < edges.size(); i++) {
			cout << edges[i].a << " " << edges[i].b << " " << edges[i].len << endl;
		}

		int mst_weight = 0;
		init_dsu();
		/*
		 Добавляем i-ое ребро в наш подграф только в том случае,
		 если данное ребро соединяет две разные компоненты связности,
		 одним из которых является наш подграф.

		 То есть, на каждом шаге добавляется минимальное
		 по весу ребро, один конец которого содержится в нашем подграфе, а другой - еще нет.
		 */
		for (edge e : edges) {
			// Если a и b находятся в разных компонентах
			if (mergeGroups(e.a, e.b)) {
				// Добавить ребро в минимальный остов
				mst_weight += e.len;
				news.push_back(e);
			}
		}
		cout << endl << "Остовной граф" << endl;
		for (int i = 0; i < news.size(); i++) {
			cout << news[i].a << " " << news[i].b << " " << news[i].len << endl;
		}

		cout << "Минимальный вес связующего дерева: " << mst_weight << endl;
		return EXIT_SUCCESS;
	}
}
