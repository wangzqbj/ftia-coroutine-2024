#include <iostream>

using namespace std;

#define crBegin               \
	static int state = 0; \
	switch (state) {      \
	case 0:

#define crReturn(x)               \
	do {                      \
		state = __LINE__; \
		return x;         \
	case __LINE__:;           \
	} while (0)

#define crFinish }

int switch_magic(void)
{
	static int i;
	crBegin for (i = 0; i < 10; i++)
	    crReturn(i);
	crFinish

	    return -1;
}

int main()
{
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	cout << switch_magic() << endl;
	return 0;
}
