namespace His_lib{
    class String {/*...*/};
    template<class T> class Vector {/*.......*/};
    //......
}

namespace Her_lib
{
template<class T> class Vector { /* ... */ };
class String {/*...*/};
}
namespace My_lib{
    using namespace His_lib ; // все из His_lib
    using namespace Her_lib; // все из Her_lib
    using His_lib::String; //разрешается в пользу His_lib
    using Her_lib::Vector; //разрешается в пользу Her_lib
    template<class T> class List { /*........*/}; // прочее
}





