#pragma once
#include <iostream>
#include "time.h"
using namespace std;
typedef string String;


static double readDouble(String str)
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
	return (T)rand() / (double) RAND_MAX * (max - min) + min;
}