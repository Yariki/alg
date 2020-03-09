#ifndef _tst_h_
#define _tst_h_

template<
    typename T,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
class TSTNode;


template<
    typename T,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
class TSTNode 
{
private:
    T value;
    char key;
    TSTNode<T> *left;
    TSTNode<T> *mid;
    TSTNode<T> *rigth;
public:
    TSTNode();
    virtual ~TSTNode();

    void setValue(const T val);
    T getValue();
    char getKey();
    void setKey(const char key);
}

template<
    typename T,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
class TST 
{

}




#endif // _tst_h_