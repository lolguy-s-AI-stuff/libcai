//This is an independent header-only tensor implementation
#ifdef __SSE2__
#include <emmintrin.h>
#endif


class Tensor {
public:
    int rows;
    int cols;
    int channels;
    float* data;

    inline Tensor(int rows, int cols, int channels){
        rows = rows;
        cols = cols;
        channels = channels;
        data = new float[rows * cols * channels];
    }
    inline Tensor(int rows, int cols, int channels, float* data){
        rows = rows;
        cols = cols;
        channels = channels;
        data = data;
    }
    inline Tensor(const Tensor& other){
        rows = other.rows;
        cols = other.cols;
        channels = other.channels;
        data = new float[rows * cols * channels];
        memcpy(data, other.data, sizeof(float) * rows * cols * channels);
    }
    inline ~Tensor(){
        delete[] data;
    }

}
inline std::ostream& operator<<(std::ostream& os, const Tensor& tensor){
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                os << tensor.data[i * tensor.cols * tensor.channels + j * tensor.channels + k] << " ";
            }
            os << "\n";
        }
    }
}

inline std::istream& operator>>(std::istream& is, Tensor& tensor){
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                is >> tensor.data[i * tensor.cols * tensor.channels + j * tensor.channels + k];
            }
        }
    }
}

inline Tensor GetRandomTensor(int rows, int cols, int channels){
    Tensor result(rows, cols, channels);
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = rand() % 2;
            }
        }
    }
    return result;
}

inline Tensor GetRandomTensor(int rows, int cols, int channels, double min, double max){
    Tensor result(rows, cols, channels);

    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = rand() % (max - min) + min;
            }
        }
    }
    return result;
}

inline Tensor GetEmptyTensor(int rows, int cols, int channels){
    Tensor result(rows, cols, channels);
    memset(result.data, 0, sizeof(double) * result.rows * result.cols * result.channels);
    //for (int i = 0; i < tensor.rows; i++){
    //    for (int j = 0; j < tensor.cols; j++){
    //        for (int k = 0; k < tensor.channels; k++){
    //            result.data[i * result.cols * result.channels + j * result.channels + k] = 0;
    //        }
    //    }
    //}
    return result;
}

#ifdef __SSE2__
inline Tensor& operator+(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    __m128 lhsd = _mm_load_pd(lhs.data);
    __m128 rhsd = _mm_load_pd(rhs.data);

    __m128 resultd = _mm_add_pd(lhsd, rhsd);

    _mm_store_pd(result.data, resultd);

    return result;
}

inline Tensor& operator-(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    __m128 lhsd = _mm_load_pd(lhs.data);
    __m128 rhsd = _mm_load_pd(rhs.data);
    
    __m128 resultd = _mm_sub_pd(lhsd, rhsd);

    _mm_store_pd(result.data, resultd);
    return result;
}

inline Tensor& operator*(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    __m128 lhsd = _mm_load_pd(lhs.data);
    __m128 rhsd = _mm_load_pd(rhs.data);
    
    __m128 resultd = _mm_mul_pd(lhsd, rhsd);

    _mm_store_pd(result.data, resultd);
    return result;
}

inline Tensor& operator/(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    __m128 lhsd = _mm_load_pd(lhs.data);
    __m128 rhsd = _mm_load_pd(rhs.data);
    
    __m128 resultd = _mm_div_pd(lhsd, rhsd);

    _mm_store_pd(result.data, resultd);
    return result;
}

inline Tensor& operator%(const Tensor& lhs,const Tensor& rhs){
        if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    __m128 lhsd = _mm_load_pd(lhs.data);
    __m128 rhsd = _mm_load_pd(rhs.data);
    
    __m128 resultd = _mm_mod_pd(lhsd, rhsd);

    _mm_store_pd(result.data, resultd);
    return result;
}


#else
inline Tensor& operator+(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = lhs.data[i * lhs.cols * lhs.channels + j * lhs.channels + k] + rhs.data[i * rhs.cols * rhs.channels + j * rhs.channels + k];
            }
        }
    }
    return result;
}

inline Tensor& operator-(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = lhs.data[i * lhs.cols * lhs.channels + j * lhs.channels + k] - rhs.data[i * rhs.cols * rhs.channels + j * rhs.channels + k];
            }
        }
    }
    return result;
}

inline Tensor& operator*(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = lhs.data[i * lhs.cols * lhs.channels + j * lhs.channels + k] * rhs.data[i * rhs.cols * rhs.channels + j * rhs.channels + k];
            }
        }
    }
    return result;
}

inline Tensor& operator/(const Tensor& lhs,const Tensor& rhs){
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = lhs.data[i * lhs.cols * lhs.channels + j * lhs.channels + k] / rhs.data[i * rhs.cols * rhs.channels + j * rhs.channels + k];
            }
        }
    }
    return result;
}

inline Tensor& operator%(const Tensor& lhs,const Tensor& rhs){
        if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels){
        std::cout << "Tensor dimensions do not match" << std::endl;
        return lhs;
    }
    Tensor result(lhs.rows, lhs.cols, lhs.channels);
    for (int i = 0; i < tensor.rows; i++){
        for (int j = 0; j < tensor.cols; j++){
            for (int k = 0; k < tensor.channels; k++){
                result.data[i * result.cols * result.channels + j * result.channels + k] = lhs.data[i * lhs.cols * lhs.channels + j * lhs.channels + k] % rhs.data[i * rhs.cols * rhs.channels + j * rhs.channels + k];
            }
        }
    }
    return result;
}

#endif