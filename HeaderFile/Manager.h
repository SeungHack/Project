#pragma once

//Pos기 실행
class Start {
public:
	void Run();
};

//관리자모드 
class AD {
public:
	void adminmode();
};

//매출현황
class Calculator {
public:
	int total = 0;
	void getMoney(); //매출현황 확인
};