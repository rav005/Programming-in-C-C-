#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

namespace w8{
	template <class T>
	class DataTable{
		int width;
		int dec;
		std::vector<T> X;
		std::vector<T> Y;

		public:
			DataTable(std::ifstream& in, int FW, int ND){
				width = FW;
				dec = ND;

				T X_temp;
				T Y_temp;

				while(!in.eof()){
					in >> X_temp;
					in >> Y_temp;

					X.push_back(X_temp);
					Y.push_back(Y_temp);
				}
				in.close();
			}
			
			T mean() const{
				T avg;
				for(int i=0; i < Y.size(); i++){
					avg += Y[i];
				}

				return avg/Y.size();
			}

			T sigma() const{
				//standard deviation = sqrt( Sum( (Yi-Ymean) * (Yi-Ymean) ) / (N-1) )
				T avg = mean();
				auto f[avg](T v) -> T{return (v-avg) * (v-avg);};
				
				T sum = 0.00;
				for(int i=0; i < Y.size(); i++){
					sum += f(Y[i]);
				}

				sum = sqrt(sum);

				return sum/Y.size()-1;
			}

			T median() const{
				std::vector<T> temp = Y;

				std::sort(temp.begin(), temp.end());

				return temp[temp.size()/2];
			}
			void regression(T& slope, T& intercept){
	//slope     = ( N * SXY - SX * SY) /( N * SXX - SX * SX)
	//intercept = (SY - slope * SX) / N
				double SXY, SX, SY, SXX;
				SXY = SX = SY = SXX = 0;
				unsigned int N = Y.size();

				for(int i=0; i < N; i++){
					SXY += X[i] * Y[i];
					SX += X[i];
					SY += Y[i];
				}
				slope = (N * SXY - SX * SY) / (N * SXX - SX * SX);
				intercept = (SY - slope * SX) / N;
			}
			void display(std::ostream& os) const{
				os << std::setw(8) << x << std::setw(8) << y << std::endl;
				for(int i=0; i < Y.size(); i++){
					os << std::setw(8) << X[i] << std::setw(8) << Y[i] << std::endl;
				}
			}
	};
	
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& src){
		src.display(os);
		return os;
	}
}