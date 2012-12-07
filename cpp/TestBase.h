/**
 * Base Class for tests
 */

#include <iostream>
#include <time.h>
using namespace std;
#include <string>

#ifndef TESTBASE_H
#define TESTBASE_H
 
class TestBase {
	private:
		string m_Desc;
		void (*m_Functocall) (void);
		
	public:
		TestBase (void (*functocall) (void), string desc)
		{
			m_Functocall = functocall;
			m_Desc = desc;
		}
		
		void Exec (int nIterations)
		{
			cout << m_Desc << " x" << nIterations << endl;
			clock_t t = clock();
			for (int i=0; i<nIterations; i++)
			{
				m_Functocall();
			}
			t = clock() - t;
			cout << ((float)t)/CLOCKS_PER_SEC << "sec" << endl;
		}
};

#endif