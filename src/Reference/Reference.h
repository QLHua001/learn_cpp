#pragma once

class Reference{

private:

    class Foo{

        public:
            Foo():_x(12.3), _a(10), _b(_x), _c(_a){};
        
        private:
            double _x;

            const int _a;
            double& _b;
            const int& _c;

    };

public:
    static void Reference_Test();

};