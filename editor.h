#define editor


class matrix_editor {
public:
    int matrix[20];
    int N = 20;
    int K = 20;
    matrix_editor() {
        int matrix[20];
        int N = 20;
    }
    int* operator + (matrix_editor m1) {
        int i, j;
        int L = 0;
        int* m3 = new int[21];
        bool element_is_original = true;
        for (i = 0; i < N; i++) {
            for (j = 0; j < m1.N; j++) {
                if (matrix[i] == m1.matrix[j])
                    element_is_original = false;
            }
            if (element_is_original) {
                m1.matrix[m1.N++] = matrix[i];
             

            }
            else {
                element_is_original = true;
            }
        }

        m3[L++] = m1.matrix[0];
        for (j = 0; j < m1.N; j++)
            if (element_not_in_array(m1.matrix[j], m3, L)) 
                m3[L++] = m1.matrix[j];
        m3[21] = L;
        return m3;
    }

    void print(int* Array, int N) {
        int i;
        for (i = 0; i < N; i++) {
            std::cout << Array[i];
            std::cout << " ";
        }
        
    }

    bool element_not_in_array(int e, int* Array, int L) {
        int i;
        bool result = true;
        for (i = 0; i < L; i++) {
            if (Array[i] == e)
                result = false;
        }
        return result;
    }

    void print() {
        int i;
        std::cout << "\n";
        for (i = 0; i < N; i++) {
            std::cout << matrix[i];
            std::cout << " ";
        }
        
    }

    int info() {
        int status = 1, i;
        for (i = 0; i < N - 1; i++)
            if (matrix[i] > matrix[i + 1])
                status = 0;
         
        return status;
    }

    void input(int K) {
        int i;
        std::cout << "INPUT MATRIX:\n";
        N = K;
        for (i = 0; i < K; i++)
            std::cin >> matrix[i];
            
    }

    void move1() {
        int i, tmp = 0, tmp2 = matrix[0];
        bool tmp_exist = false;
        for (i = 0; i < N - 1; i++) {
            if (!tmp_exist) {
                tmp = matrix[i + 1];
                matrix[i + 1] = matrix[i];
                tmp_exist = true;
            }
            else {
                tmp2 = matrix[i + 1];
                matrix[i + 1] = tmp;
                tmp = tmp2;
            }
        }
        matrix[0] = tmp2;

    }

    void move2() 
    {   
        int number = 2;
        while (number) {
            number -= 1;
            move1();
        }
    }



};