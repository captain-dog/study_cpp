#include <iostream>
#include <ctime>
#include "Fractal_serpinsk.h"


int main() {
	/*
	* Ïîñòðîåíèå ôðàêòàëà ñåðïèíñêîãî
	*/
	srand(time(0));

	int rows = 550, 
		cols = 700; // ðàçìåðû ïîëÿ

	Field field(rows, cols);
	
	// ïîðÿäîê ïåðåäà÷è êîîðäèíàò - x, y
	Point pA(10, 530), // èíèöèàëèçàöèÿ òî÷åê âåðøèí òðåóãîëüíèêà pApBpC
		pB(680, 530), 
		pC(350, 5),
		curr_p(20, 70); // èíèöèàëèçàöèÿ ñòàðòîâîé òî÷êè

	Fractal_serpinsk f_serp(&pA, &pB, &pC, &curr_p, &field);

	f_serp.run();

	return 0;
}