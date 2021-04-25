#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const int W = 12;         // ширина рабочего пол€
const int H = 8;         // высота рабочего пол€
const int WALL = -1;         // непроходима€ €чейка
const int BLANK = -2;         // свободна€ непомеченна€ €чейка

int px[W * H], py[W * H];      // координаты €чеек, вход€щих  путь
int len;                       // длина пути
int grid[H][W];                // рабочее поле

// ѕеред вызовом lee() массив grid заполнен значени€ми WALL и BLANK

bool lee(int ax, int ay, int bx, int by)   // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
{
	int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
	int dy[4] = { 0, 1, 0, -1 };   // справа, снизу, слева и сверху
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return false;  // €чейка (ax, ay) или (bx, by) - стена

	// распространение волны
	d = 0;
	grid[ay][ax] = 0;            // стартова€ €чейка помечена 0
	do {
		stop = true;               // предполагаем, что все свободные клетки уже помечены
		for (y = 0; y < H; ++y)
			for (x = 0; x < W; ++x)
				if (grid[y][x] == d)                         // €чейка (x, y) помечена числом d
				{
					for (k = 0; k < 4; ++k)                    // проходим по всем непомеченным сосед€м
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							grid[iy][ix] == BLANK)
						{
							stop = false;              // найдены непомеченные клетки
							grid[iy][ix] = d + 1;      // распростран€ем волну
						}
					}
				}
		d++;
	} while (!stop && grid[by][bx] == BLANK);

	if (grid[by][bx] == BLANK) return false;  // путь не найден

	// восстановление пути
	len = grid[by][bx];            // длина кратчайшего пути из (ax, ay) в (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // записываем €чейку (x, y) в путь
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // переходим в €чейку, котора€ на 1 ближе к старту
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;                    // теперь px[0..len] и py[0..len] - координаты €чеек пути
	return true;
}






class Maze {
private:
	vector<vector<int>> maze;
	int exit[2];
	int start[2];
public:
	void load_file(const string& file_name);
	void print() const;
	void search();
};



//int check(int x, int y)
//{
//	int** maze;
//	int temp;
//	int cnt = 0;
//	if (x != 0 && maze[y][x - 1] == 0)
//	{
//		maze[y][x - 1] = temp + 1;
//		cnt++;
//	}
//	if (x != sizex - 1 && maze[y][x + 1] == 0)
//	{
//		maze[y][x + 1] = temp + 1;
//		cnt++;
//	}
//	if (y != 0 && maze[y - 1][x] == 0)
//	{
//		maze[y - 1][x] = temp + 1;
//		cnt++;
//	}
//	if (y != sizey - 1 && maze[y + 1][x] == 0)
//	{
//		maze[y + 1][x] = temp + 1;
//		cnt++;
//	}
//	return cnt;
//}







void Maze::search() {

}


void Maze::print() const {
	for (auto& stroke : maze) {
		for (auto& val : stroke) 
			cout << val << ' ';
		cout << endl;
	}
};


vector<int> split(const char* str, char c = ' ')
{
	vector<int> result;
	do
	{
		const char* begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(stoi(string(begin, str)));
	} while (0 != *str++);

	return result;
}



//void Maze::load_file(const string& file_name) {
//	fstream file(file_name);
//	if (!file.is_open()) throw exception("file not found");
//	maze.clear();
//	string stroke;
//	bool exit_found = false;
//	bool start_found = false;
//	while (getline(file, stroke)) {
//		auto line = split(stroke.c_str());
//		if (!exit_found || !start_found) {
//			for (auto& val : line) {
//				if ()
//
//
//
//			}
//		}
//		maze.push_back();
//	}
//	file.close();
//}





int main() {
	
	int z = 2;
	std::shared_ptr<int> x (new int(12));



	return 0;
}