#pragma once

#include"type_traits.h"
#include"stl_iterator.h"
#include"stl_construct.h"

/*

template <class OutputIterator, class Size, class T>
OutputIterator fill_n(OutputIterator first, Size n, const T& value) 
{
  for ( ; n > 0; --n, ++first)
    *first = value;
  return first;
}
*/

template<class ForwardIterator, class Size, class T>
ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first, Size n, const T &x, __true_type)
{
	return fill_n(first, n, x);
}

template<class ForwardIterator, class Size, class T>
ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first, Size n, const T &x, __false_type)
{
	ForwardIterator cur = first;
	for(; n>0; --n, ++cur)
		construct(&*cur, x);
	return cur;
}

template<class ForwardIterator, class Size, class T, class T1>
ForwardIterator __uninitialized_fill_n(ForwardIterator first, Size n, const T &x, T1*)
{
	cout<<"T1 = "<<typeid(T1).name()<<endl;
	typedef typename __type_traits<T1>::is_POD_type is_POD;
	return __uninitialized_fill_n_aux(first, n, x, is_POD());
}

template<class ForwardIterator, class Size, class T>
ForwardIterator my_uninitialized_fill_n(ForwardIterator first, Size n, const T &x)
{
	return __uninitialized_fill_n(first, n, x, value_type(first));
}