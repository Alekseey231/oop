#include <glm/mat4x4.hpp>

class Matrix4
{
    public:
        Matrix4() = default;
        Matrix4(std::initializer_list<std::initializer_list<float>> init_list);

        virtual ~Matrix4() = default;
        virtual Matrix4 operator*(const Matrix4 &matrix) const = 0;
};

class Matrix4GLM : public Matrix4
{
    public:
        virtual ~Matrix4GLM() = default;
        Matrix4GLM() = default;
        Matrix4GLM(std::initializer_list<std::initializer_list<float>> init_list)  
        {
            size_t rows = init_list.size();
            auto it = init_list.begin();
            size_t cols = it->size();

            for (const auto &row_list: init_list)
                if (row_list.size() != cols)
                {
                    //throw Wrong_Init_List_Exception(__FILE__, __LINE__, __TIME__, "wrong size of initializer row (must be equal)");
                }

            size_t i = 0;
            for (const auto &ilist: init_list)
                for (const auto &elem: ilist)
                {
                    this->matr[i / cols][i % cols] = elem;
                    i++;
                }
        }

        Matrix4 operator*(const Matrix4 &matrix) const override
        {
            return Matrix4GLM(this->matr * dynamic_cast<const Matrix4GLM&>(matrix).matr);
        }
    private:
        Matrix4GLM(glm::mat4 m) : matr(m) {};
        glm::mat4 matr;
};