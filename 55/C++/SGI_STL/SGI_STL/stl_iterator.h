#pragma once

template <class T>
inline T* value_type(const T*) 
{
	return (T*)(0); 
}