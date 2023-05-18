#include "./vector/vector.h"
#include <concepts>

using namespace my_math;
#include <vector>
#include <complex>

int main()
{
    Vector<std::complex<int>> m2333{1,1,1};
    std::initializer_list<int> k = {1,2,3};
    Vector<int> new_vec_of;
    new_vec_of = k;
    std::cout << new_vec_of;
    //Vector<double> my_vec{1,2,3};
    //auto new_vec(my_vec);
    //Vector<int> int_vec(my_vec);
    //Vector<double> double_vec(my_vec);
    //std::cout << double_vec;
    //std::cout << new_vec;
    //const Iterator<int> iter = my_vec.begin();
    //auto new_iter = 1+iter;
    //std::vector<int> vec{1,2,3};
    //std::cout << vec.rbegin() - vec.rend() << std::endl;
    //ConstIterator<int> m;
    //Vector<int> new_vec(my_vec.crbegin(), my_vec.crend());
    //std::cout << my_vec.rbegin() - my_vec.rend();
    //Vector<int> vec = {12,3,5};
    //const Iterator<int> iter = vec.begin();
    //*iter = 5;
    //std::vector<int> stdvec= {1,2,3};
    //vec = stdvec;
    //++iter;
    Vector<double> vec1{1.5, 2, 15};
    Vector<float> vec2(3);
    Vector<int> vec3{3, 6, 8};
    Vector<int> vec4(vec3);
    Vector<double> vec5(vec1);

    std::vector<int> any_vec{1,2,3};
    Vector<double> vec6(vec1.begin(), vec1.end());
    
    std::cout << "vec1 " << vec1 << std::endl;
    std::cout << "vec2 " << vec2 << std::endl;
    std::cout << "vec3 " << vec3 << std::endl;
    std::cout << "vec4 " << vec4 << std::endl;
    std::cout << "vec5 " << vec5 << std::endl;

    std::cout << "Sum operation with vectors\n";

    std::cout << "+ : " << vec1 << " + " << vec5 << " = " << (vec1+vec5) << std::endl;
    std::cout << "+ : " << vec1 << " + " << vec3 << " = " << (vec1.sum_with_vec(vec3)) << std::endl;
    std::cout << "+= : " << vec1 << " + " << vec1 << " = " << vec1.sum_with_equal(vec1) << std::endl;
    std::cout << "+= : " << vec1 << " + " << vec1 << " = " << (vec1+=vec1) << std::endl;

    std::cout << "Sub operation with vectors\n";

    vec1 = {1.5, 2.5, 3.5};
    vec3 = {3, 2, 1};
    vec4 = {1, 2, 3};
    std::cout << "- : " << vec1 << " - " << vec3 << " = " << (vec1-vec3) << std::endl;
    std::cout << "- : " << vec1 << " - " << vec3 << " = " << (vec1.sub_with_vec(vec3)) << std::endl;
    std::cout << "-= : " << vec3 << " - " << vec4 << " = " << vec3.sum_with_equal(vec4) << std::endl;
    std::cout << "-= : " << vec3 << " + " << vec4 << " = " << (vec3+=vec4) << std::endl;

    std::cout << "Scalar product\n";

    vec3 = {1, 3 , 5};
    vec4 = {2, 4, 6};
    std::cout << vec3 << " * " << vec4 << " = " << (vec3 * vec4) << std::endl;
    vec3 = {5,4,3,2,1};
    vec4 = {0,0,0,0,1};
    std::cout << vec3 << " * " << vec4 << " = " << (vec3 * vec4) << std::endl;
    vec3 = {5,4,3,2,1};
    vec4 = {0,0,0,0,1};
    std::cout << vec3 << " * " << vec4 << " = " << (vec3.scalar_product(vec4)) << std::endl;

    std::cout << "Vector product\n";

    vec3 = {0, 0, 1};
    vec4 = {0, 1, 0};
    std::cout << vec3 << " * " << vec4 << " = " << (vec3 & vec4) << std::endl;
    vec3 = {5,4,3};
    vec4 = {7,0,1};
    std::cout << vec3 << " * " << vec4 << " = " << (vec3 & vec4) << std::endl;
    std::cout << vec3 << " * " << vec4 << " = " << (vec3 &= vec4) << std::endl;
    vec3 = {5,4,3};
    std::cout << vec3 << " * " << vec4 << " = " << (vec3.vector_product_equal(vec4)) << std::endl;
    vec1 = {5.5,4.3,3.8};
    std::cout << vec1 << " * " << vec4 << " = " << (vec1.vector_product(vec4)) << std::endl;

    std::cout << "Angle between vectors\n";
    vec3 = {0, 0, 1};
    vec4 = {0, 1, 0};
    std::cout << (vec3.angle_between(vec4)) << std::endl;

    vec3 = {2, 5, 6};
    std::cout << "Normilize vectors\n";
    std::cout << (vec3.normalize()) << std::endl;

    std::cout << "Is vector zero\n";
    std::cout << (vec2.is_vector_zero()) << " - " << vec2 << std::endl;
    std::cout << (vec3.is_vector_zero()) << " - " << vec3 << std::endl;

    int num_i = 5;
    double num_d = 0.5;

    std::cout << "Operation vector with num\n";

    Vector<int> my_vec = {1,2,3};
    std::cout << "+ : " << my_vec << " + " << num_d << " = " << (my_vec + num_d) << std::endl;
    std::cout << "+ : " << my_vec << " + " << num_i << " = " << (my_vec.sum_with_num(num_i)) << std::endl;
    std::cout << "+= : " << my_vec << " + " << num_i << " = " << my_vec.sum_with_equal(num_i) << std::endl;
    my_vec = {1,2,3};
    std::cout << "+= : " << my_vec << " + " << num_i << " = " << (my_vec+=num_i) << std::endl;
    my_vec = {1,2,3};

    std::cout << "- : " << my_vec << " - " << num_d << " = " << (my_vec - num_d) << std::endl;
    std::cout << "- : " << my_vec << " - " << num_i << " = " << (my_vec.sub_with_num(num_i)) << std::endl;
    std::cout << "-= : " << my_vec << " - " << num_i << " = " << my_vec.sub_with_equal(num_i) << std::endl;
    my_vec = {1,2,3};
    std::cout << "-= : " << my_vec << " - " << num_i << " = " << (my_vec-=num_i) << std::endl;
    my_vec = {1,2,3};

    std::cout << "* : " << my_vec << " / " << num_d << " = " << (my_vec * num_d) << std::endl;
    std::cout << "* : " << my_vec << " / " << num_i << " = " << (my_vec.mul_with_num(num_i)) << std::endl;
    std::cout << "*= : " << my_vec << " / " << num_i << " = " << my_vec.mul_with_equal(num_i) << std::endl;
    my_vec = {1,2,3};
    std::cout << "*= : " << my_vec << " / " << num_i << " = " << (my_vec*=num_i) << std::endl;
    my_vec = {1,2,3};

    std::cout << "/ : " << my_vec << " / " << num_d << " = " << (my_vec / num_d) << std::endl;
    std::cout << "/ : " << my_vec << " / " << num_i << " = " << (my_vec.div_with_num(num_i)) << std::endl;
    std::cout << "/= : " << my_vec << " / " << num_i << " = " << my_vec.div_with_equal(num_i) << std::endl;
    my_vec = {1,2,3};
    std::cout << "/= : " << my_vec << " / " << num_i << " = " << (my_vec/=num_i) << std::endl;
    my_vec = {1,2,3};
    
    Vector<double> m = {1.5,2,3,4,5};
    m+=1;
    std::cout << m;
    
    //auto el = *(m.rend());
    //std::cout << el;

    std::cout << (5 + m) << std::endl;
    auto new_vec = std::move(my_vec);
    auto iter = new_vec.rbegin();
    std::cout << *iter << std::endl;
    ++iter;
    //std::cout << *) << std::endl;
    Vector<int> vec234 = {1,2,3,4};
    std::cout << "\n";
    for(auto iter = vec234.rbegin(); iter != vec234.rend(); iter+=1)
    {
        std::cout << *iter << std::endl;
    }
    auto iter2 = vec234.rbegin();
    iter2+=2;
    iter2-=1;
    iter2+=1;
    --iter2;
    std::cout << *(iter2+1) << std::endl;
    std::cout << (iter != iter2) << std::endl;
    auto iter3 = std::move(new_vec.begin());
    //iter3 = std::move(new_vec.begin());
    //std::cout << *iter3;

    std::cout << "\n";
    //std::cout << *(4 + vec234.begin()) << std::endl;

    iter = std::move(iter2);
    
    Vector<int> m123{1,2,3};
    m123[1] = 5;
    //{
        //Vector<int> vec_1 = {1,2,3};
        //Iterator<int> iter45454(vec_1);
        //ConstIterator<int> iterr45454(vec_1);
        ///ConstIterator<int> iter_c = iter;
    //}
    /*{
        Vector<int> new_vector{12,34,45,67};
        for(Iterator<int> iter = new_vector.begin(); iter != new_vector.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
        for(auto iter = new_vector.cbegin(); iter != new_vector.cend(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
        
    }
    */
    //std::cout << *iter2;
    //std::cout << (vec234.rbegin() - vec234.rend()) << std::endl;
    return 0;
}