#include <iostream>
#include<fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char*** opt_1_for_inserting_item(char***, int, int);
char*** opt_2_for_displaying_item(char***, int, int);
char*** opt_3_for_deleting_item(char***, int, int);
char*** opt_4_for_deleting_all_items(char***, int, int);
char*** opt_5_for_returning_items_in_shelf(char***, int, int);
void opt_6_for_returning_total_no_of_items(char***, int, int);
void opt_7_for_finding_item(char***, int, int);
char*** opt_8_for_updating_item(char***, int, int);
char*** opt_9_to_check_if_shelf_is_empty(char***, int, int);
char*** opt_10_to_check_if_shelf_is_full(char***, int, int);
void store_record_in_file(char***, int, int);
int main(int argc, char** argv) {
	cout << "												//Shelf_No" << endl;
	cout << "Enter No Of Shelves : ";
	int no_of_shelves = 0;
	cin >> no_of_shelves;           // Number Of Rows
	cout << endl;
	char*** no_of_shelves_arr = new char** [no_of_shelves];
	cout << "												//Position_No" << endl;
	cout << "Enter No Of Positions On Each Shelf : ";
	int positions_of_each_shelf = 0;     //Number Of Coulmns On Each Shelf
	cin >> positions_of_each_shelf;
	cout << endl;
	cout << "\t              ***************************************************" << endl;
	cout << "\t              *                                                 *" << endl;
	cout << "\t              * Welcome To Departmental Store Management System *" << endl;
	cout << "\t              *                                                 *" << endl;
	cout << "\t              ***************************************************" << endl;
	cout << endl;
	cout << "                                     **************** " << endl;
	cout << "                                     *     MENU     *" << endl;
	cout << "                                     **************** " << endl;

	for (int i = 0; i < no_of_shelves; i++) {
		no_of_shelves_arr[i] = new char* [positions_of_each_shelf];
	}
	for (int i = 0; i < no_of_shelves; i++) {
		for (int j = 0; j < positions_of_each_shelf; j++) {
			no_of_shelves_arr[i][j] = nullptr;
		}
	}
	int opt = 0;
	do {
		cout << endl;
		cout << "(1)Press 1 For Inserting An Item " << endl;
		cout << "(2)Press 2 For Displaying All Items " << endl;
		cout << "(3)Press 3 For Remove An Item " << endl;
		cout << "(4)Press 4 For Remove All The Items " << endl;
		cout << "(5)Press 5 For Return Total No Of Items In Specific Shelf" << endl;
		cout << "(6)Press 6 For Return Total No Of Items " << endl;
		cout << "(7)Press 7 For Find An Item " << endl;
		cout << "(8)Press 8 For Updating An Item " << endl;
		cout << "(9)Press 9 To Check If Shelf Is Empty " << endl;
		cout << "(10)Press 10 To Check If Shelf Is Full " << endl;
		cout << "(11)Press 0 To Exit " << endl;
		cout << "Choose Option : ";
		cin >> opt;
		cout << endl;
		if (opt == 1) {
			opt_1_for_inserting_item(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);

		}
		if (opt == 2) {
			opt_2_for_displaying_item(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 3) {
			opt_3_for_deleting_item(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 4) {
			opt_4_for_deleting_all_items(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 5) {
			opt_5_for_returning_items_in_shelf(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 6) {
			opt_6_for_returning_total_no_of_items(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 7) {
			opt_7_for_finding_item(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 8) {
			opt_8_for_updating_item(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 9) {
			opt_9_to_check_if_shelf_is_empty(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 10) {
			opt_10_to_check_if_shelf_is_full(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);
		}
		if (opt == 0) {
			store_record_in_file(no_of_shelves_arr, no_of_shelves, positions_of_each_shelf);

			for (int i = 0; i < no_of_shelves; i++) {
				for (int j = 0; j < positions_of_each_shelf; j++) {

					delete[]no_of_shelves_arr[i][j];
					//	no_of_shelves_arr[i][j] = nullptr;


				} delete[] no_of_shelves_arr[i];
			}
			delete[] no_of_shelves_arr;
			no_of_shelves_arr = nullptr;
			cout << "Thanks For Using This Program " << endl;

		}
		if (opt > 10) {
			cout << "Please Enter Valid Options " << endl;
		}
	} while (opt != 0);
	system("Pause");
	return 0;
}
char*** opt_1_for_inserting_item(char*** shelves_arr, int shelf_no_from_main, int position_no_from_main) {
	int* shelf_no = new int(0);
	int* position_no = new int(0);
	cout << "												     //Shelf" << endl;
	cout << "Enter Shelf : ";
	cin >> *shelf_no;

	if (*shelf_no > shelf_no_from_main || *shelf_no == 0) {
		cout << "You Have Choosen More Than Given Shlef.  //If You Want More Shelf Then Please Exit Program And Select Required Shelfs " << endl;
		delete shelf_no;
		shelf_no = nullptr;
		delete position_no;
		position_no = nullptr;
		return shelves_arr;
	}

	*shelf_no = *shelf_no - 1;
	cout << "													//Position_No" << endl;
	cout << "Enter Position_no : ";
	cin >> *position_no;
	if (*position_no > position_no_from_main || *position_no == 0) {
		cout << "You Have Choosen More Than Given Positions. //If You Want More Space Then Please Exit Program And Select More Positions " << endl;
		delete shelf_no;
		shelf_no = nullptr;
		delete position_no;
		position_no = nullptr;
		return shelves_arr;
	}
	*position_no = *position_no - 1;
	if ((shelves_arr[*shelf_no][*position_no]) != nullptr) {
		cout << "There Is Not Enough Space To Insert Item" << endl;
	}
	else {

		char* item_name = new char[100];
		cin.ignore();
		cout << "                                                   //Item_Name" << endl;
		cout << "Enter Item : ";
		cin.getline(item_name, 99);
		int count = 0;
		for (int i = 0; item_name[i] != '\0'; i++) {
			count++;
		}
		shelves_arr[*shelf_no][*position_no] = new char[count];
		shelves_arr[*shelf_no][*position_no][count] = '\0';

		for (int i = 0; item_name[i] != '\0'; i++) {
			shelves_arr[*shelf_no][*position_no][i] = item_name[i];
		}
		cout << "SuccessFully Added " << endl;
		delete[] item_name;
		item_name = nullptr;
	}
	delete shelf_no;
	shelf_no = nullptr;
	delete position_no;
	position_no = nullptr;
	return shelves_arr;
}
char*** opt_2_for_displaying_item(char*** arr, int shelf_no_from_main, int position_no_from_main) {
	int  flag = 0;
	int total_num_of_positions = shelf_no_from_main * position_no_from_main;
	for (int i = 0; i < shelf_no_from_main; i++) {
		for (int j = 0; j < position_no_from_main; j++) {
			if (arr[i][j] == nullptr) {
				flag++;
			}
		}
	}
	if (total_num_of_positions == flag) {
		cout << endl;
		cout << "Please Put Some Items In Shelf First ." << endl;
		cout << endl;
		return arr;
	}
	else {
		cout << endl;
		for (int i = 0; i < shelf_no_from_main; i++) {
			for (int j = 0; j < position_no_from_main; j++) {
				if (arr[i][j] != nullptr) {
					cout << "Row No : " << i + 1 << ", Postions No : " << j + 1 << ", Item : " << arr[i][j] << endl;

				}
			}
		}
		cout << endl;

	}
	return arr;
}

char*** opt_3_for_deleting_item(char*** arr, int number_of_shelfs, int number_of_positions) {
	cout << endl;
	int* shelf_no = new int(0);
	int* position_no = new int(0);
	int* count = new int(0);
	int* flag = new int(0);
	cout << "													//Shelf_No " << endl;
	cout << "Enter Shelf No To Remove Item : " << endl;
	cin >> *shelf_no;
	if (*shelf_no > number_of_shelfs || *shelf_no == 0) {
		cout << endl;
		cout << "Please Enter Valid Shelf_No " << endl;
		cout << endl;
		delete shelf_no;
		shelf_no = nullptr;
		delete position_no;
		position_no = nullptr;
		delete count;
		count = nullptr;
		delete flag;
		flag = nullptr;
		return arr;
	}
	cout << "Enter Position : ";
	cin >> *position_no;
	if (*position_no > number_of_positions || *position_no == 0) {
		cout << endl;
		cout << "Please Enter Valid Number Of Positions " << endl;
		cout << endl;
		delete shelf_no;
		shelf_no = nullptr;
		delete position_no;
		position_no = nullptr;
		delete count;
		count = nullptr;
		delete flag;
		flag = nullptr;
		return arr;
	}
	*shelf_no = *shelf_no - 1;
	*position_no = *position_no - 1;
	for (int i = *shelf_no; i < *shelf_no + 1; i++) {
		for (int j = *position_no; j < *position_no + 1; j++) {
			if (arr[i][j] == nullptr) {
				*flag = 1;
			}
			else {
				*flag = 0;
			}
		}
	}
	if (*flag == 1) {
		cout << endl;
		cout << "There Is No Need To Delete This Item As It Is Already Empty " << endl;
		cout << endl;

		delete shelf_no;
		shelf_no = nullptr;
		delete position_no;
		position_no = nullptr;
		delete count;
		count = nullptr;
		delete flag;
		flag = nullptr;
		return arr;
	} if (*flag == 0) {
		cout << endl;
		cout << "This Item Can Be Deleted " << endl;
		cout << endl;
		delete[] arr[*shelf_no][*position_no];
		arr[*shelf_no][*position_no] = nullptr;
		cout << "Item Has Been SuccesFully Deleted " << endl;
		cout << endl;
	}
	delete shelf_no;
	shelf_no = nullptr;
	delete position_no;
	position_no = nullptr;
	delete count;
	count = nullptr;
	delete flag;
	flag = nullptr;
	return arr;
}

char*** opt_4_for_deleting_all_items(char*** arr, int num_of_shelfs, int num_of_positions) {
	int flag = 0;
	for (int i = 0; i < num_of_shelfs; i++) {
		for (int j = 0; j < num_of_positions; j++) {
			if (arr[i][j] != nullptr) {
				delete[]arr[i][j];
				arr[i][j] = nullptr;
				flag = 1;
			}
		}
	}
	cout << endl;
	if (flag != 1) {
		cout << "Every Shell Is Already Empty " << endl;
		cout << endl;
	}
	else {
		cout << "All Items Removed From Every Shelf! " << endl;
		cout << endl;
	}

	// cout<<arr[0][0][0]<<endl;
	return arr;
}


char*** opt_5_for_returning_items_in_shelf(char*** arr, int number_of_shelfs, int number_of_positions) {
	int* shelf_no = new int(0);
	cout << endl;
	cout << "												//Shelf_No" << endl;
	cout << "Please Enter Shelf No To Count Total Number Of Items " << endl;
	cin >> *shelf_no;
	cout << endl;
	if (*shelf_no == 0 || *shelf_no > number_of_shelfs) {
		cout << endl;
		cout << "Please Enter Valid Shelf_No " << endl;
		cout << endl;
		return  arr;
	}
	else {
		*shelf_no = *shelf_no - 1;
		int* count = new int(0);
		for (int j = 0; j < number_of_positions; j++) {
			if (arr[*shelf_no][j] != nullptr) {
				(*count)++;
			}
		}
		if (*count != 0) {
			cout << endl;
			cout << "Number Of Items In A Shelf Are : " << *count << endl;
			cout << endl;
		}
		else {
			cout << endl;
			cout << "Shelf Is Already Empty " << endl;
			cout << endl;
		}
		delete  count;
		count = nullptr;
	}
	delete shelf_no;
	shelf_no = nullptr;
	return arr;
}
void opt_6_for_returning_total_no_of_items(char*** arr, int total_shelfs, int total_positions) {
	int* count = new int(0);
	for (int i = 0; i < total_shelfs; i++) {
		for (int j = 0; j < total_positions; j++) {
			if (arr[i][j] != nullptr) {
				(*count)++;
			}
		}
	}
	if (*count == 0) {
		cout << endl;
		cout << "All The Shelfs Are Empty " << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "Number Of Items In All The Shelfs Are : " << *count << endl;
		cout << endl;
	}
	delete count;
	count = nullptr;
}
void opt_7_for_finding_item(char*** arr, int shelfs, int positions) {
	char* item_name = new char[100];
	cin.ignore();
	cout << endl;
	cout << "											Item_Name " << endl;
	cout << "Enter Item Name To Find : ";
	cin.getline(item_name, 99);
	cout << endl;
	int* count = new int(0);
	for (int i = 0; item_name[i] != '\0'; i++) {
		(*count)++;
	}
	int* flag = new int(0);
	bool item_found = false;
	for (int i = 0; i < shelfs; i++) {
		for (int j = 0; j < positions; j++) {
			if (arr[i][j] != nullptr) {
				*flag = 0;
				for (int c = 0; item_name[c] != '\0' && arr[i][j][c] != '\0'; c++) {
					if (item_name[c] == arr[i][j][c]) {
						(*flag)++;
					}
				}
				if (*flag == *count) {
					cout << endl;

					cout << "Shelf_No : " << i + 1 << "  Position_No : " << j + 1 << endl;
					cout << endl;
					item_found = true;
				}
			}
		}
	}
	if (item_found) {
		cout << endl;
		cout << "Item Has Been Found!" << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "Item Not Found " << endl;
		cout << endl;
	}
	delete[] item_name;
	item_name = nullptr;
	delete flag;
	flag = nullptr;
	delete count;
	count = nullptr;
}


char*** opt_8_for_updating_item(char*** arr, int total_shelfs, int total_position) {
	char* item_name = new char[50];
	int* shelf_no = new int(0);
	int* position_no = new int(0);
	cout << "										//Shelf_No" << endl;
	cout << "Enter Shelf No : ";
	cin >> *shelf_no;
	if (*shelf_no > total_shelfs || *shelf_no == 0) {
		cout << endl;
		cout << "Please Enter Valid Shelf_No " << endl;
		cout << endl;
		delete shelf_no;
		shelf_no = nullptr;
		delete  item_name;
		item_name = nullptr;
		delete  position_no;
		position_no = nullptr;
		return arr;
	}
	cout << "Enter Position : ";
	cin >> *position_no;
	if (*position_no > total_position || *position_no == 0) {
		cout << endl;
		cout << "Please Enter Valid Number Of Positions " << endl;
		cout << endl;
		delete shelf_no;
		shelf_no = nullptr;
		delete  item_name;
		item_name = nullptr;
		delete  position_no;
		position_no = nullptr;
		return arr;
	}
	*shelf_no = *shelf_no - 1;
	*position_no = *position_no - 1;
	delete[] arr[*shelf_no][*position_no];
	arr[*shelf_no][*position_no] = nullptr;
	cout << endl;
	cout << "										//Item_Name " << endl;
	cout << "Enter Item To Update With : ";
	cout << endl;
	cin.ignore();
	cin.getline(item_name, 49);
	int* count = new int(0);
	for (int i = 0; item_name[i] != '\0'; i++) {
		(*count)++;
	}
	arr[*shelf_no][*position_no] = new char[*count];
	for (int i = 0; item_name[i] != '\0'; i++) {
		arr[*shelf_no][*position_no][i] = item_name[i];
	}
	cout << endl;
	cout << "Shelf Updated! " << endl;
	cout << endl;
	delete shelf_no;
	shelf_no = nullptr;
	delete position_no;
	position_no = nullptr;
	delete[] item_name;
	item_name = nullptr;
	delete count;
	count = nullptr;
	return arr;
}


char*** opt_9_to_check_if_shelf_is_empty(char*** arr, int total_shelfs, int total_positions) {
	int* check_shelf = new int(0);
	cout << "Enter Shelf No : ";
	cin >> *check_shelf;
	if (*check_shelf > total_shelfs || *check_shelf == 0) {
		cout << endl;
		cout << "Invalid Shelf No!" << endl;
		cout << endl;
		delete check_shelf;
		check_shelf = nullptr;
		return arr;

	}
	*check_shelf = *check_shelf - 1;
	int* flag = new int(0);
	for (int i = *check_shelf; i < *check_shelf + 1; i++) {
		for (int j = 0; j < total_positions; j++) {
			if (arr[i][j] == nullptr) {
				(*flag)++;
			}
		}
	}
	if (*flag == total_positions) {
		cout << endl;
		cout << "All The Positions In Shelf Is Empty! " << endl;

	}
	else {
		cout << endl;
		cout << "Full Shelf Is Not Empty!" << endl;
		int* count = new int(0);
		int* store_loc = new int[*flag];
		for (int i = *check_shelf; i < *check_shelf + 1; i++) {
			for (int j = 0; j < total_positions; j++) {
				if (arr[i][j] == nullptr) {
					store_loc[*count] = j;
					(*count)++;
				}
			}
		}

		for (int i = 0; i < *count; i++) {
			cout << endl;
			cout << "Position : " << store_loc[i] + 1 << " Is Empty " << endl;
		}
		cout << endl;
		delete count;
		count = nullptr;
		delete[]store_loc;
		store_loc = nullptr;
	}
	delete check_shelf;
	check_shelf = nullptr;
	delete flag;
	flag = nullptr;
	return arr;
}

char*** opt_10_to_check_if_shelf_is_full(char*** arr, int total_shefls, int total_positions) {
	int* shelf_no = new int(0);
	cout << "											//Shelf_No" << endl;
	cout << "Enter Shelf No ";
	cout << endl;
	cin >> *shelf_no;
	if (*shelf_no > total_shefls || *shelf_no == 0) {
		cout << endl;
		cout << "Invalid Shelf No!" << endl;
		cout << endl;
		delete shelf_no;
		shelf_no = nullptr;
		return arr;

	}
	*shelf_no = *shelf_no - 1;
	int* flag = new int(0);
	for (int i = *shelf_no; i < *shelf_no + 1; i++) {
		for (int j = 0; j < total_positions; j++) {
			if (arr[i][j] != nullptr) {
				(*flag)++;
			}
		}
	}
	if (*flag == total_positions) {
		cout << endl;
		cout << "Shelf " << *shelf_no + 1 << " Is Full! " << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "Shelf " << *shelf_no + 1 << " Is Not Full! " << endl;
		cout << endl;
	}
	delete shelf_no;
	shelf_no = nullptr;
	delete flag;
	flag = nullptr;
	return arr;
}

void store_record_in_file(char*** arr, int shelves, int positions) {
	ofstream store;
	store.open("Record.txt");
	for (int i = 0; i < shelves; i++) {
		for (int j = 0; j < positions; j++) {
			if (arr[i][j] != nullptr) {


				store << "Shelf_No\tPosition_No\t Item" << endl;
				store << i + 1 << "\t\t" << j + 1 << "\t\t " << arr[i][j] << endl;
			}
		}
	}
	store.close();
}