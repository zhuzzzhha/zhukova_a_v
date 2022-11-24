#include <cmath>
#include <matplot/matplot.h>
#include<vector>
#include <chrono>
#include <string>
#include <random>
#include <fstream>
#include <thread>
#include<unordered_set>

std::string toString(int val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}
using namespace matplot;
int main() {
	using namespace matplot;
	std::vector<double> x_input_1;
	std::vector<double> y_input_1;

	std::vector<double> x_input_2;
	std::vector<double> y_input_2;

	std::vector<double> x_program;
	std::vector<double> y_program_1;
	std::vector<double> y_program_2;



	std::random_device rd;
	std::mt19937 gen(rd());

	std::ofstream file_in;

	std::string line;
	std::ifstream file_out;


	for (int coef = 2; coef < 202; coef += 10)
	{
		for (int i = 100000; i < 200000; i += 1000)
		{
			int N = i;
			std::vector<int> my_data;
			for (int j = 1; j <= N / coef; j++) // генерируем данные в соответствии с текущим коэффициентом уникальности k
			{
				my_data.push_back(j);
			}
			// поток для записи
			file_in.open("C:\\zhukova_a_v\\prj.lab\\task_3\\data.txt"); // окрываем файл для записи
			if (file_in.is_open())
			{
				file_in << N << std::endl;
			}
			for (int i = 0; i < N; i += 1)
			{

				if (file_in.is_open())
				{
					file_in << my_data[i % (N / coef)] << std::endl;
				}
			}
			file_in.close();


			int n = 0;

			//ввод данных в 1 алгоритме
			auto start_input_1 = std::chrono::high_resolution_clock::now();
			file_out.open("C:\\zhukova_a_v\\prj.lab\\task_3\\data.txt");
			std::vector<int> as(200001, -1);
			if (file_out.is_open())
			{
				file_out >> n;

				for (int i = 0; i < n; i += 1)
				{
					int idx = 0;
					file_out >> idx;
					as[idx] = n - i - 1;
				}
			}
			auto end_input_1 = std::chrono::high_resolution_clock::now();
			file_out.close();


			file_out.open("C:\\zhukova_a_v\\prj.lab\\task_3\\data.txt", std::ofstream::out | std::ofstream::trunc);
			int k;

			//1 алгоритм
			auto start_program_1 = std::chrono::high_resolution_clock::now();
			k = std::distance(as.begin(), std::max_element(as.begin(), as.end()));
			auto end_program_1 = std::chrono::high_resolution_clock::now();

			//ввод данных 2 алгоритм

			auto start_input_2 = std::chrono::high_resolution_clock::now();
			file_out.open("C:\\zhukova_a_v\\prj.lab\\task_3\\data.txt");
			if (file_out.is_open())
				file_out >> n;
			std::vector<int> data(n, 0);
			if (file_out.is_open())
			{
				for (int i = 0; i < n; i += 1)
				{
					file_out >> data[i];
				}
			}
			auto end_input_2 = std::chrono::high_resolution_clock::now();

			//2 алгоритм
			auto start_program_2 = std::chrono::high_resolution_clock::now();
			std::unordered_set<int> unique;
			unique.reserve(200000);
			int idx_unique = n;
			for (int i = n - 1; 0 <= i; i -= 1)
			{
				if (!unique.contains(data[i])) {
					idx_unique = data[i];
					unique.insert(idx_unique);
				}
			}
			auto end_program_2 = std::chrono::high_resolution_clock::now();


			std::chrono::duration<double> duration_input_1 = end_input_1 - start_input_1;
			std::chrono::duration<double> duration_program_1 = end_program_1 - start_program_1;

			std::chrono::duration<double> duration_input_2 = end_input_2 - start_input_2;
			std::chrono::duration<double> duration_program_2 = end_program_2 - start_program_2;


			y_input_1.push_back((duration_input_1.count()) / i);
			x_input_1.push_back(i);

			y_input_2.push_back((duration_input_2.count()) / i);
			x_input_2.push_back(i);

			y_program_1.push_back((duration_program_1.count()) / i);
			y_program_2.push_back((duration_program_2.count()) / i);
			x_program.push_back(i);
		}
		y_input_1 = transform(y_input_1, [](auto y_input_1) { return (y_input_1); });
		y_program_1 = transform(y_program_1, [](auto y_program_1) { return (y_program_1); });

		//1 алгоритм
		tiledlayout(2, 1);
		nexttile();
		subplot(2, 1, 0);
		title("1st algorithm time");
		auto p1 = plot(x_input_1, y_input_1, "-xr");
		hold(on);
		auto p2 = plot(x_program, y_program_1, "-o");
		p1->display_name("input_time");
		p2->display_name("program_time");

		ylabel("t/n");
		xlabel("n");

		//2алгоритм
		subplot(2, 1, 1);
		title("2nd algorithm time");
		auto p3 = plot(x_input_2, y_input_2, "-xr");
		hold(on);
		auto p4 = plot(x_program, y_program_2, "-o");
		p3->display_name("input_time");
		p4->display_name("program_time");

		ylabel("t/n");
		xlabel("n");

		nexttile();


		std::string name = "img" + toString((coef - 1) / 10) + ".jpg";
		std::cout << name;
		save(name);

		p1.reset();
		p2.reset();
		p3.reset();
		p4.reset();
		std::ofstream report_out;
		report_out.open("C:\\zhukova_a_v.build\\prj.lab\\task_3\\Debug\\report.md");
		if (report_out.is_open())
		{
			report_out << "![[" + name + "]]";
		}
		report_out.close();
	}
	return 0;
}
