#include <string>
class Lights{
	public:
		Lights();
		Lights(const Lights& L);
		~Lights();
		bool getRed();
		bool getYellow();
		bool getGreen();
		void setRed(bool status);
		void setYellow(bool status);
		void setGreen(bool status);
		void SetOn(std::string color);
	private:
		bool Red;
		bool Yellow;
		bool Green;
};