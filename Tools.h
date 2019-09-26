#pragma once
#include <iostream>
using namespace std;
typedef string String;

static double readDobule(String str)
{
	double tmp;
	cout << "Please Enter the " << str << ": ";
	cin >> tmp;
	return tmp;
}

static String readString(String str)
{
	String tmp;
	cout << "Please Enter the " << str << ": ";
	cin >> tmp;
	return tmp;
}

static int readInt(String str)
{
	int tmp;
	cout << "Please Enter the " << str << ": ";
	cin >> tmp;
	return tmp;
}

template <typename T>
static T random(T min, T max)
{
	srand(time(NULL));
	return (T)rand() / (double) RAND_MAX * (max - min) + min;
}