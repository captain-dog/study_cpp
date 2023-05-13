#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

/*
симуляция работы парадокса Монти Холла
*/
//ведущий
namespace presenter {
	std::vector<bool> doors;
	void gen_doors() {
		doors.clear();
		for (int i = 0; i < 3; i++)
		{
			doors.push_back(false);
		}
		doors.at(rand() % 3) = true;
	}

	//TODO
	int open_door_with_a_goat(int door_guess) {
		// door_guess - дверь, которую игрок предполагает открыть
		// функция вернёт ему дверь с козой, кроме выбранной
		for (int i = 0; i < doors.size(); i++)
		{
			if (i != door_guess and !doors.at(i))
			{
				return i;
			}
		}

		return -1;
	}

}


// логика парадокса Монти Холла
namespace logic {
	int percentage_of_luck = 0;
	int count = 1000; // количество сыгранных игр

	void print_vector(std::vector<bool> vect) {
		for (int val : vect) std::cout << val << "\t";
		std::cout << std::endl;
	}

	bool pick_a_door(int ndoor) {
		return presenter::doors.at(ndoor);
	}

	void print_doors() {
		for (bool door : presenter::doors) std::cout << door << "\t";
		std::cout << std::endl;
	}

	void proccess_without_changes() {
		/*
		* Симуляция работы без смены двери
		*/
		std::cout << std::endl << "==================== NEW GAME \t NEW GAME =================" << std::endl;

		int number_of_trues = 0;

		for (int i = 0; i < count; i++)
		{
			presenter::gen_doors();
			number_of_trues += pick_a_door(rand() % 3) ? 1 : 0;
		}
		percentage_of_luck = (number_of_trues * 100) / count;
		std::cout << "number won cars = " << number_of_trues << "; played " << count << " games without changing doors." << std::endl;
		std::cout << "\t percentage of luck: " << percentage_of_luck << " %" << std::endl;
	}

	void proccess_with_changes() {
		int number_of_trues = 0;
		int door_with_a_goat; // скажет ведущий
		int door_i_guess_with_a_car; // я буду предполагать, что машина будет в этой двери


		std::vector<bool> doors_i_know_i_dont_wanna_open;

		for (int i = 0; i < count; i++)
		{
			std::cout << std::endl << "==================== NEW GAME \t NEW GAME =================" << std::endl;
			int door_my_final_guess = -1;

			presenter::gen_doors();
			doors_i_know_i_dont_wanna_open.clear();
			for (int i = 0; i < presenter::doors.size(); i++) doors_i_know_i_dont_wanna_open.push_back(false);

			door_i_guess_with_a_car = rand() % 3;
			doors_i_know_i_dont_wanna_open.at(door_i_guess_with_a_car) = true;

			door_with_a_goat = presenter::open_door_with_a_goat(door_i_guess_with_a_car);
			doors_i_know_i_dont_wanna_open.at(door_with_a_goat) = true;


			// change doors
			printf("doors generated: ");
			print_doors();
			std::cout << "door i guess with a car: " << door_i_guess_with_a_car << std::endl;
			std::cout << "door the presenter says contains a goat: " << door_with_a_goat << std::endl;


			for (int i = 0; i < doors_i_know_i_dont_wanna_open.size(); i++)
			{
				std::cout << "(do i wanna open door) " << i << "? " << std::endl;
				if (!doors_i_know_i_dont_wanna_open.at(i)) {
					door_my_final_guess = i;
					break;
				}
			}
			assert(door_my_final_guess >= 0);
			std::cout << "so now i wanna choose this door: " << door_my_final_guess << std::endl;
			number_of_trues += pick_a_door(door_my_final_guess) ? 1 : 0;
		}


		percentage_of_luck = (number_of_trues * 100) / count;
		std::cout << "number of trues = " << number_of_trues << "; played " << count << " games." << std::endl;
		std::cout << "\t percentage of luck: " << percentage_of_luck << " %" << std::endl;
	}

}

class KillMe {
public:
	KillMe() {}

	~KillMe() {
		delete this;
	}
};

int main() {
	srand(time(NULL));
	KillMe* killme = new KillMe;
	delete killme;

	return 0;
}