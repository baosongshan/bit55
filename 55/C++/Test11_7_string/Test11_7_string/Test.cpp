#include<iostream>
#include<string>
using namespace std;

//fjaljflakjaljflafajlfa

void main()
{
	string s;
	//cin>>s;  //' '  \n
	getline(cin, s);  //  \n  jfla falfjla 
	cout<<s<<endl;
}

/*
void main()
{
	string s("HelxoBit."); 
	//string tmp = s.substr();
	//string tmp = s.substr(3);
	string tmp = s.substr(3, 2);
	cout<<tmp<<endl;
}

/*
void main()
{
	string s("HelxoBit.");  //15
	string sub("Bi");
	//size_t index = s.find("HelloBit", 4, 4);
	//size_t index = s.find('H', 7);
	size_t index = s.rfind('x');
	if(index == string::npos) //npos
	{
		cout<<"Error."<<endl;
	}
	else
		cout<<index<<endl;
}

/*
void main()
{
	string s("Hello");  //15
	cout<<strlen(s.c_str())<<endl;
}

/*
void main()
{
	string s("Hello");  //15
	string s1("BitWorld.");
	char *str = "Bit.";

	//s.append(s1); //
	//s.append(s1, 3, 5);
	//s.append(str);
	//s.append(str,50);
	//s.append(s1.begin(), s1.end());

	s += s1;
	cout<<s<<endl;

}

/*
void main()
{
	string s;
	cout<<s.size()<<endl;
	cout<<s<<endl;
	s.push_back('a');
	cout<<s.size()<<endl;
	cout<<s<<endl;
	s.push_back('b');
	cout<<s.size()<<endl;  
	cout<<s<<endl;

	s.pop_back();
	cout<<s.size()<<endl;  
	cout<<s<<endl;
}

/*
void main()
{
	string s("Hello");
	cout<<s<<endl;    //1
	for(int i=0; i<s.size(); ++i)
		cout<<s[i];
	cout<<endl;
	string::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;

	string::reverse_iterator rit = s.rbegin();
	while(rit != s.rend())
	{
		cout<<*rit;
		++rit;
	}
	cout<<endl;

	for(auto e : s)
		cout<<e;
	cout<<endl;

	for(int i=0; i<s.size(); ++i)
		cout<<s.at(i); 
	cout<<endl;

}

/*
void main()
{
	string s;
	s.reserve(100); ////////
	for(int i=1; i<=100; ++i)
	{
		cout<<i<<": "<<s.capacity()<<endl;
		s.push_back(i);
	}
}

/*
void main()
{
	string s("Hello");
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;

	s.clear();
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;
}

/*
void main()
{
	string s("Helloaaaaaaaaaaaaaaaa");
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;

	s.resize(10, 'x'); //Hello00000
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;

}

/*
void main()
{
	string s;
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;

	s.reserve(100);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;

	s.reserve(20);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;

}

/*
void main()
{
	string s;
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;

	s.resize(100);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;  //

	s.resize(10);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;  //

}

/*
void main()
{
	string s("Hello");
	cout<<s.size()<<endl;
	cout<<s.length()<<endl;
	cout<<s.capacity()<<endl;
	s.clear();
	cout<<s.empty()<<endl;
}

/*
//string (const string& str, size_t pos, size_t len = npos);

void main()
{
	string s;
	cout<<s<<endl;
	//char *str = "Hello";
	string s1("Hello");
	cout<<s1<<endl;
	string s2(10, 'a');
	cout<<s2<<endl;
	string s3(s2);
	cout<<s3<<endl;

	string s4(s3, 2, 3);
}
*/