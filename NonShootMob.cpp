#include "NonShootMob.h"

NonShootMob::NonShootMob(std::string name) : EntityWalk(name){
	this->name = name;
    //Присваиваем значение переменным в зависимости от значения name
	if (name == "Tikva") {
		damage = 10;
        scoreperdeath = 15;
	}
    else if (name == "Ghost") {
        damage = 20;
        scoreperdeath = 30;
    }
    else if (name == "BossLight") {
        damage = 50;
        scoreperdeath = 100;
    }
    else if (name == "BossHard") {
        damage = 100;
        scoreperdeath = 500;
    }
}

void NonShootMob::Update(Player&player, float time, NonShootMob& walk, Map& map, float CurrentFrame) {

    //Получаем значения позиций игрока и существа, позиция игрока считается целью, к которой идёт моб

    player.x = round((int)player.sprite.getGlobalBounds().left / 32);
    player.y = round((int)player.sprite.getGlobalBounds().top / 32);
    walk.x = round((int)walk.sprite.getGlobalBounds().left/ 32);
    walk.y = round((int)walk.sprite.getGlobalBounds().top/ 32);

    //Создаем экземпляр класса поиска пути, создаем пару координат позиция существа и игрока, первый y второй х

    PathFinding finder;
    PathFinding::Pair mobposition = make_pair(walk.y, walk.x);
    PathFinding::Pair targetposition = make_pair(player.y , player.x);
    if (mobposition != targetposition) {
        if (walk.mapposition.empty()) {
            //Вызываем функцию поиска пути через алгоритм A*, передаем в фукнцию моба, карту, позицию моба, позицию таргета
            finder.aStarSearch(walk, map, mobposition, targetposition);
        }
        else {
            if (walk.mapposition[0].first == walk.y && walk.mapposition[0].second == walk.x) {
                //итератор на первый элемент вектор, удаляем его, тк он всегда равен текущей позиции существа
                auto it = walk.mapposition.begin();
                walk.mapposition.erase(it);
                //передвижение моба строго по 4 сторонам с помощью координат
                if (walk.mapposition[0].first > walk.y) {
                    walk.rect.top += walk.dy * time;
                }
                else if (walk.mapposition[0].first < walk.y) {
                    walk.rect.top -= walk.dy * time;
                }
                else if (walk.mapposition[0].second > walk.x) {
                    walk.rect.left += walk.dx * time;
                }
                else if (walk.mapposition[0].second < walk.x) {
                    walk.rect.left -= walk.dx * time;
                }
                //устанавливаем позицию спрайт, очищаем вектор
                walk.sprite.setPosition(walk.rect.left, walk.rect.top);
                walk.mapposition.clear();
            }
            else {
                //передвижение моба строго по 4 сторонам с помощью координат
                if (walk.mapposition[0].first > walk.y) {
                    walk.rect.top += dy * time;
                }
                else if (walk.mapposition[0].first < walk.y) {
                    walk.rect.top -= dy * time;
                }
                else if (walk.mapposition[0].second > walk.x) {
                    walk.rect.left += dx * time;
                }
                else if (walk.mapposition[0].second < walk.x) {
                    walk.rect.left -= dx * time;
                }
                //устанавливаем позицию спрайт, очищаем вектор
                walk.sprite.setPosition(walk.rect.left, walk.rect.top);
                walk.mapposition.clear();
            }
            
        }
    }
}

//###################################PATHFINDING#################################

struct PathFinding::cell {
    //Координаты родительской ячейки
    //F = G + H
    int parent_i, parent_j;
    double f, g, h;
};

bool PathFinding::isValid(int row ,int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool PathFinding::isUnBlocked(Map& map, int row, int col) {
    if (map.map[row][col] == 1 || map.map[row][col] == 2) {
        return false;
    }
    else {
        return true;
    }
}

bool PathFinding::isDestination(int row, int col, Pair dest) {
    if (row == dest.first && col == dest.second) {
        return true;
    }
    else {
        return false;
    }
}

double PathFinding::calculateHValue(int row, int col, Pair dest) {
    return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}

void PathFinding::tracePath(NonShootMob& mob, cell cellDetails[][COL], Pair dest) {

    int row = dest.first; 
    int col = dest.second;


    stack<Pair> Path;

    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col))
    {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while (!Path.empty())
    {
        //Обращаемся к верхнему элементу
        pair<int, int> p = Path.top();
        Path.pop();
        
        mob.mapposition.push_back(p);
       
        //std::cout << p.second << " " << p.first << std::endl;
    }

    return;
}

void PathFinding::aStarSearch(NonShootMob& mob, Map& map, Pair src, Pair dest) {

    //Закрытый список
    bool closedList[ROW][COL];
    //Присваиваем диапазону false
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closedList[i][j] = false;
        }
    }
    //Массив структур
    cell cellDetails[ROW][COL];

    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cellDetails[i][j].f = 1000;
            cellDetails[i][j].g = 1000;
            cellDetails[i][j].h = 1000;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
    //Задаем значения для первой ячейки

    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    //Множество открытый спискок с значением H и координат
    set<pPair> openList;
    //Добавляем в множество первую ячейку
    openList.insert(make_pair(0.0, make_pair(i, j)));

    
    bool foundDest = false;

    while (!openList.empty())
    {
        pPair p = *openList.begin();

        
        openList.erase(openList.begin());

        
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        //G, H, F для поиска
        double gNew, hNew, fNew;

        //Вверх
        if (isValid(i - 1, j) == true)
        {
           
            if (isDestination(i - 1, j, dest) == true)
            {
                
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                
                tracePath(mob, cellDetails, dest);
                foundDest = true;
                return;
            }
            
            else if (closedList[i - 1][j] == false && isUnBlocked(map, i - 1, j) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;

                
                if (cellDetails[i - 1][j].f == 1000 || cellDetails[i - 1][j].f > fNew)
                {
                    openList.insert(make_pair(fNew, make_pair(i - 1, j)));

                    
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }

       //Вниз
        if (isValid(i + 1, j) == true)
        {
           
            if (isDestination(i + 1, j, dest) == true)
            {
               
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                
                tracePath(mob, cellDetails, dest);
                foundDest = true;
                return;
            }
           
            else if (closedList[i + 1][j] == false && isUnBlocked(map, i + 1, j) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;

               
                if (cellDetails[i + 1][j].f == 1000 || cellDetails[i + 1][j].f > fNew)
                {
                    openList.insert(make_pair(fNew, make_pair(i + 1, j)));
                 
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }

       //Вправо
        if (isValid(i, j + 1) == true)
        {
            
            if (isDestination(i, j + 1, dest) == true)
            {
               
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                
                tracePath(mob, cellDetails, dest);
                foundDest = true;
                return;
            }

            
            else if (closedList[i][j + 1] == false && isUnBlocked(map, i, j + 1) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;

               
                if (cellDetails[i][j + 1].f == 1000 || cellDetails[i][j + 1].f > fNew)
                {
                    openList.insert(make_pair(fNew, make_pair(i, j + 1)));

                   
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }

        //Влево
        if (isValid(i, j - 1) == true)
        {
           
            if (isDestination(i, j - 1, dest) == true)
            {
               
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
               
                tracePath(mob, cellDetails, dest);
                foundDest = true;
                return;
            }

          
            else if (closedList[i][j - 1] == false && isUnBlocked(map, i, j - 1) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;

               
                if (cellDetails[i][j - 1].f == 1000 || cellDetails[i][j - 1].f > fNew)
                {
                    openList.insert(make_pair(fNew,make_pair(i, j - 1)));

                    
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }
    }
}