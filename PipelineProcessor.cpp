// CompArch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdint>

using namespace std;
// Binary Struct for I type
struct Bin1 {
	string op = "";
	string rs = "";
	string rt = "";
	string address = "";
};

// Binary Struct for R type
struct Bin2 {
	string op = "";
	string rs = "";
	string rt = "";
	string rd = "";
	string shamt = "";
	string funct = "";
};

// Instruction  I type Struct
struct IType {
	string op = "";
	string rs = "";
	string rt = "";
	string address = "";
};

// Instruction  R type Struct
struct RType {
	string op = "";
	string rs = "";
	string rt = "";
	string rd = "";
	
};

//Register Struct
struct Register {
	string name = "";
	string val;
};

struct Memory {
	string locale;
	string value;
};

// converting I type instructions
string convertOP(string val) { 
	if (val == "001000") {
		return "ADDI";
	}
	else if (val == "000100") {
		return "BEQ";
	}
	else if (val == "000101") {
		return "BNE";
	}
	else if (val == "100011") {
		return "LW";
	}
	else if (val == "101011") {
		return "SW";
	}
}
// Converting R type instructions
string convertFunct(string val) {
	if (val == "100000") {
		return "ADD";
	}
	else if (val == "100010") {
		return "SUB";
	}
	else if (val == "101010") {
		return "SLT";
	}
}

// Converting Binary to Registers
string convertReg(string val) {
	if (val == "00000") {
		return "R0";
	}
	else if (val == "00001") {
		return "R1";
	}
	else if (val == "00010") {
		return "R2";
	}
	else if (val == "00011") {
		return "R3";
	}
	else if (val == "00100") {
		return "R4";
	}
	else if (val == "00101") {
		return "R5";
	}
	else if (val == "00110") {
		return "R6";
	}
	else if (val == "00111") {
		return "R7";
	}
	else if (val == "01000") {
		return "R8";
	}
	else if (val == "01001") {
		return "R9";
	}
	else if (val == "01010") {
		return "R10";
	}
	else if (val == "01011") {
		return "R11";
	}
	else if (val == "01100") {
		return "R12";
	}
	else if (val == "01101") {
		return "R13";
	}
	else if (val == "01110") {
		return "R14";
	}
	else if (val == "01111") {
		return "R15";
	}
	else if (val == "10000") {
		return "R16";
	}
	else if (val == "10001") {
		return "R17";
	}
	else if (val == "10010") {
		return "R18";
	}
	else if (val == "10011") {
		return "R19";
	}
	else if (val == "10100") {
		return "R20";
	}
	else if (val == "10101") {
		return "R21";
	}
	else if (val == "10110") {
		return "R22";
	}
	else if (val == "10111") {
		return "R23";
	}
	else if (val == "11000") {
		return "R24";
	}
	else if (val == "11001") {
		return "R25";
	}
	else if (val == "11010") {
		return "R26";
	}
	else if (val == "11011") {
		return "R27";
	}
	else if (val == "11100") {
		return "R28";
	}
	else if (val == "11101") {
		return "R29";
	}
	else if (val == "11110") {
		return "R30";
	}
	else if (val == "11111") {
		return "R31";
	}
}

string BinToString(string val) {

	string value = "";
	int e;
	int x = 0;
	for (int i = 15; i > -1; i--) {
		e = val[i] - '0';
		x += (e * ((int)pow(2, i)));
	}
	value = to_string(x);
	return value;
}

int main()
{
	bool another = false;
	do {

		std::cout << "Please enter the name of your text file followed with '.txt' below:" << endl;
		string filen;
		cin >> filen;
		ifstream ifs(filen);
		if (!ifs.is_open()) {
			std::cout << "file not open." << endl;
		}
		else 
		{
			//Ask for Output file
			cout << "Please enter the name of your OUTPUT file followed with '.txt' below:" << endl;
			string filout;
			cin >> filout;
			ofstream ifs2;
			ifs2.open(filout);

			string reg = "REGISTERS";
			string mem = "MEMORY";
			string code = "CODE";
			string curword;
			string thing, thing2, thing3, thing4;
			string regc;
			string memc;
			string codec;
			//uint32_t codes[20];
			Register regs[100];
			Memory mems[100];
			string codes1[100];
			int i = 0;
			int r = 0;
			int m = 0;
			int n = 0;

			//Formatted Output Varriables 
			int count = 1;
			int instrcuction_count = 1;

			while (getline(ifs, curword) && !ifs.eof()) {
				if (curword == reg || curword == mem || curword == code) {
					getline(ifs, curword);
					while (curword != mem) {				// This while loop takes in the registers fromt the
						stringstream s(curword);			// input file and puts them in a struct and those 
															// structs are in an array of 100 
						getline(s, thing, ' ');
						getline(s, thing2);

						regs[r].name = thing;
						regs[r].val = thing2;

						r++;
						getline(ifs, curword);
					}
					n++;
				}
				else if (n > 0) {						// I have no clue what the fuck this part is for
					while (curword != code) {
						// Or what I'm supposed to do with this part

						stringstream a(curword);
						getline(a, thing3, ' ');
						getline(a, thing4);
						mems[m].locale = thing3;
						mems[m].value = thing4;
						m++;
						getline(ifs, curword);
					}
					n = 0;
				}
				else if (n == 0) {
					while (!ifs.eof()) {				// This part just takes the binary values and puts 
						codes1[i] = curword;			// them in a array 
						i++;
						getline(ifs, curword);
					}
					codes1[i] = curword;
					i++;
				}
			}
			/*for (int j = 0; j < r; j++) {
				cout << regs[j] << endl;
			}
			cout << endl;
			for (int o = 0; o < m; o++) {
				cout << mems[o] << endl;
			}
			cout << endl;
			for (int f = 0; f < i; f++) {
				cout << codes1[f] << endl;
			}*/

			const int num = i;								// " i " is the total number of instructions
			//Initialize Variables for Execution
			Bin1 val;
			Bin2 val2;
			IType trans;
			RType trans2;
			Register curr_reg;
			string opcode = "";
			bool reg_already_exist = false;
			int hold;

			for (int j = 0; j < i; j++) {					// itereate through the array of binary instructions
				for (int h = 0; h < 6; h++) {				// get the opcode for the binary instruction
					opcode += codes1[j][h];
				}

				if (opcode == "000000") {					// Check if its a R type instruction
					val2.op = opcode;						// Add the opcode to the binary struct 
					for (int z = 6; z < 11; z++) {			// Add the "rs" to the binary struct
						val2.rs += codes1[j][z];
					}
					for (int u = 11; u < 16; u++) {			// Add the "rt" to the binary struct
						val2.rt += codes1[j][u];
					}
					for (int k = 16; k < 21; k++) {			// Add the "rd" to the binary struct
						val2.rd += codes1[j][k];
					}
					for (int p = 21; p < 26; p++) {			//Add the "shamt" to the binary struct
						val2.shamt += codes1[j][p];
					}
					for (int q = 26; q < 32; q++) {			//Add the "funct" to the binary struct
						val2.funct += codes1[j][q];
					}

					// Formatted Output: Instruction has been loaded in
					ifs2 << "C#" << count << " I" << instrcuction_count << "-IF" << endl;
					count++;

					// Decode the R type binary Instruction
					trans2.op = convertFunct(val2.funct);
					trans2.rs = convertReg(val2.rs);
					trans2.rt = convertReg(val2.rt);
					trans2.rd = convertReg(val2.rd);

					//Formatted Output: Instruction has been deocoded
					ifs2 << "C#" << count << " I" << instrcuction_count << "-ID" << endl;
					count++;

					//std::cout  << val2.op << val2.rs << val2.rt << val2.rd << val2.shamt << val2.funct << endl;
					//std::cout << trans2.op << " " << trans2.rd << " " << trans2.rs << " " << trans2.rt << endl;

					// Begin Executions 

					if (trans2.op == "ADD")					//Add Function
					{
						int x = 0, y = 0, r2 = r;
						for (int c = 0; c < r2; c++) {
							if (regs[c].name == trans2.rs) {
								string a = regs[c].val;
								x = stoi(a);
							}
							if (regs[c].name == trans2.rt) {
								string b = regs[c].val;
								y = stoi(b);
							}
							if (regs[c].name == trans2.rd) {	// Check if the register already exist in the array
								reg_already_exist = true;
								hold = c;
							}
						}
						if (reg_already_exist) {
							regs[hold].val = to_string(x + y);
						}
						else {
							curr_reg.name = trans2.rd;
							curr_reg.val = to_string(x + y);
							regs[r] = curr_reg;
							r++;
						}
					}
					else if (trans2.op == "SUB")				//Subtraction Function
					{
						int x = 0, y = 0, r2 = r;
						for (int c = 0; c < r2; c++) {
							if (regs[c].name == trans2.rs) {	// Find rs in the register array
								string a = regs[c].val;
								x = stoi(a);
							}
							if (regs[c].name == trans2.rt) {	// Find rt in the register array
								string b = regs[c].val;
								y = stoi(b);
							}
							if (regs[c].name == trans2.rd) {	// Check if the register already exist in the array
								reg_already_exist = true;
								hold = c;
							}
						}
						if (reg_already_exist) {
							regs[hold].val = to_string(x - y);
						}
						else {
							curr_reg.name = trans2.rd;
							curr_reg.val = to_string(x - y);
							regs[r] = curr_reg;
							r++;
						}
					}
					else if (trans2.op == "SLT")				//Set Less Than Function
					{
						int x = 0, y = 0, r2 = r;
						string set = "";
						for (int c = 0; c < r2; c++) {
							if (regs[c].name == trans2.rs) {	// Find rs in the register array
								string a = regs[c].val;
								x = stoi(a);
							}
							if (regs[c].name == trans2.rt) {	// Find rt in the register array
								string b = regs[c].val;
								y = stoi(b);
							}
							if (regs[c].name == trans2.rd) {	// Check if the register already exist in the array
								reg_already_exist = true;
								hold = c;
							}
						}
						if (reg_already_exist) {
							if (x < y)
								set = "1";
							else
								set = "0";
							//Update the Register
							regs[hold].val = set;
						}
						else {
							curr_reg.name = trans2.rd;
							if (x < y)
								set = "1";
							else
								set = "0";
							//Update the Register
							curr_reg.val = set;
							regs[r] = curr_reg;
							r++;
						}
					}
					//Formatted Output: Instruction has been excuted
					ifs2 << "C#" << count << " I" << instrcuction_count << "-EX" << endl;
					count++;
					//Formatted Output: Instruction has been written
					ifs2 << "C#" << count << " I" << instrcuction_count << "-WB" << endl;
					count++;
					instrcuction_count++;
				}
				// I type instructions
				else {
					val.op = opcode;
					for (int t = 6; t < 11; t++) {
						val.rs += codes1[j][t];
					}
					for (int s = 11; s < 16; s++) {
						val.rt += codes1[j][s];
					}
					for (int g = 16; g < 32; g++) {
						val.address += codes1[j][g];
					}


					trans.op = convertOP(val.op);
					trans.rs = convertReg(val.rs);
					trans.rt = convertReg(val.rt);
					trans.address = BinToString(val.address);

					if (trans.op == "LW") {
						string qr;
						for (int d = 0; d < r; d++) {
							if (regs[d].name == trans.rs) {

							}
						}

					}
					else if (trans.op == "SW") {

					}
					else if (trans.op == "ADDI") {
						for (int v = 0; v < r; v++) {
							if (regs[v].name == trans.rs) {

							}
						}
					}

					//Formatted Output for I type
					/*
					if (trans.op == "BNE" || trans.op == "BEQ") {
						std::cout << val.op << val.rs << val.rt << val.address << endl;
						std::cout << trans.op << " " << trans.rs << " " << trans.rt << endl;
					}
					else {
						std::cout << val.op << val.rs << val.rt << val.address << endl;
						std::cout << trans.op << " " << trans.rt << " " << trans.rs << endl;
					}
					*/
				}
				opcode = "";
				val.op = "";
				val.rs = "";
				val.rt = "";
				val.address = "";

				val2.op = "";
				val2.rs = "";
				val2.rt = "";
				val2.rd = "";
				val2.shamt = "";
				val2.funct = "";
			}

			// close the output file
			ifs2.close();

			std::cout << val.op << endl;
			string ans;
			cout << "Would you like another round of MIPS simuation? Yes or No?:" << endl;
			cin >> ans;
			if (ans == "Yes" || ans == "yes" || ans == "YES") {
				another = true;
			}
			else {
				another = false;
			}
		}
	}while (another);

	cout << "Done";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
