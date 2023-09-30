#pragma once
#include <iostream> 
#include "Form.h"
#include <ctime>
#include <iomanip>

using namespace std;

//CreateL2.cpp
int CreateL2(Form& f);
void CreateHead(Form& f);

//Swap.cpp
void Swap(Form& f, int i, int j);
void ChangeOrd(Form f);
void SubsElem(Form& f);

//Helper.cpp
void OutList(Form f);
void Clear();
void Check(Form& f);
int LenList(Form f);
void CheckEmpty(Form f);

//ListInList.cpp
void ListInList(Form f1, Form& f2);
void FirstListInList(Form f1, Form& f2);
void LastListInList(Form f1, Form& f2);

//Get.cpp
L2* GetElemInd(Form f, int& ind);
L2* GetInd(Form f, int& ind, bool type);

//Add.cpp
void AddElemEnd(Form& f);
void AddOneElEnd(Form& f);
void AddOneElTop(Form& f);
void AddElInd(Form& f, int ind);
void AddListEnd(Form& f);
void AddListBeg(Form& f);
void AddListInd(Form& f, int ind);

//Del.cpp
void DelList(Form& f);
void DelLast(Form& f);
void DelHead(Form& f);
void DelElemInd(Form& f, int ind);

