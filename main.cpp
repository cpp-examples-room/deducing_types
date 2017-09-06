#include <boost/type_index.hpp>
#include <iostream>

using boost::typeindex::type_id_with_cvr;

template<typename T>
void f_tr(T& param) {
    std::cout << "  T:         " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "  ParamType: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
    std::cout << std::endl;
}

template<typename T>
void f_tcr(T const& param) {
    std::cout << "  T:         " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "  ParamType: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
    std::cout << std::endl;
}

template<typename T>
void f_tp(T* param) {
    std::cout << "  T:         " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "  ParamType: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
    std::cout << std::endl;
}

template<typename T>
void f_trr(T&& param) {
    std::cout << "  T:         " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "  ParamType: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
    std::cout << std::endl;
}

template<typename T>
void f_t(T param) {
    std::cout << "  T:         " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "  ParamType: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
    std::cout << std::endl;
}

int main()
{
    int x_i = 0;
    int const x_ic = 0;
    int const& x_icr = 0;

    std::cout << "template<typename T>" << std::endl;
    std::cout << "void f(ParamType param);" << std::endl;
    std::cout << std::endl;

    std::cout << "-------------------" << std::endl;
    std::cout << "Вывод типа шаблона:" << std::endl;
    std::cout << "-------------------" << std::endl;

    std::cout << "ParamType ==" << std::endl;
    std::cout << "  1. * или & (!= &&):" << std::endl;
    std::cout << "  2. &&:" << std::endl;
    std::cout << "  3. != *, &, &&" << std::endl;
    std::cout << std::endl;

/*
    1. * или & (!= &&):

        Ссылочная часть выражения игнорируется.
        Затем выполняется сопоставление типа expr с ParamType для определения типа T.
*/

    std::cout << "template<typename T>" << std::endl;
    std::cout << "void f_tr(T& param):" << std::endl;
    std::cout << std::endl;

    std::cout << "f_tr(int):" << std::endl;
    f_tr(x_i);

    std::cout << "f_tr(int const):" << std::endl;
    f_tr(x_ic);

    std::cout << "f_tr(int const&):" << std::endl;
    f_tr(x_icr);

    std::cout << "template<typename T>" << std::endl;
    std::cout << "void f_tcr(T const& param):" << std::endl;
    std::cout << std::endl;

    std::cout << "f_tcr(int):" << std::endl;
    f_tcr(x_i);

    std::cout << "f_tcr(int const):" << std::endl;
    f_tcr(x_ic);

    std::cout << "f_tcr(int const&):" << std::endl;
    f_tcr(x_icr);

    std::cout << "template<typename T>" << std::endl;
    std::cout << "void f_tp(T* param):" << std::endl;
    std::cout << std::endl;

    std::cout << "f_tp(int*):" << std::endl;
    f_tp(&x_i);

    std::cout << "f_tp(int const*):" << std::endl;
    f_tp(&x_ic);

/*
    2. &&:

        Если выражение lvalue, то T и ParamType выводится как lvalue-ссылки.
        Если выражение rvalue, то см. правило 1.
*/

    std::cout << "template<typename T>" << std::endl;
    std::cout << "void f_trr(T&& param):" << std::endl;
    std::cout << std::endl;

    std::cout << "f_trr(int):" << std::endl;
    f_trr(x_i);

    std::cout << "f_trr(int const):" << std::endl;
    f_trr(x_ic);

    std::cout << "f_trr(int const&):" << std::endl;
    f_trr(x_icr);

    std::cout << "f_trr(int rvalue):" << std::endl;
    f_trr(1);

/*
    3. != *, &, &&

        Ссылочная часть выражения игнорируется.
        Затем отбрасываются const и volatile
        и выполняется сопоставление типа expr с ParamType для определения типа T.
*/

    std::cout << "template<typename T>" << std::endl;
    std::cout << "void f_t(T param):" << std::endl;
    std::cout << std::endl;

    std::cout << "f_t(int):" << std::endl;
    f_t(x_i);

    std::cout << "f_t(int const):" << std::endl;
    f_t(x_ic);

    std::cout << "f_t(int const&):" << std::endl;
    f_t(x_icr);

    std::cout << "f_t(int rvalue):" << std::endl;
    f_t(1);
};
