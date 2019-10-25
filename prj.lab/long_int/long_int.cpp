#include<long_int/long_int.h>
#include<string>
#include<iomanip>
#include<algorithm>

void Long_int::operator=(Long_int long_int) {
	data_ = long_int.ReadFrom();
}

std::vector<uint32_t> Long_int::ReadFrom() const{
	return data_;
}

uint32_t Long_int::ReadFrom(int i)const {
	return data_[i];
}

bool Long_int::IsPositive() const {
	return positive;
}

std::istream& operator>>(std::istream& stream, Long_int& long_int) {
	std::string s;
	stream >> s;
	std::vector<uint32_t> v;
	for (size_t i = s.size(); i > 0;i-=9) {
		if (i >= 9) {
			v.push_back(stoi(s.substr(i - 9, 9)));
		}
		else {
			v.push_back(stoi(s.substr(0, i)));
		}
	}
	long_int = Long_int(v);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Long_int& long_int) {
	std::string a;
	bool first = true;
	for (int i = (int)long_int.ReadFrom().size() - 1; i >= 0; --i) {
		if (first) {
			stream << long_int.ReadFrom(i);
			first = false;
		}
		else {
			stream << std::setfill('0') << std::setw(9) << long_int.ReadFrom(i);
		}
	}
	return stream;
}

Long_int Long_int::operator+=(Long_int rhs) {
	if (positive && !rhs.IsPositive()) {
		positive = !positive;
		rhs -= *this; // (first + (-second)) = -((-first) + second) = -(second - first)
		positive = !positive;
	}
	else if (!positive && rhs.IsPositive()) {
		positive = !positive;
		*this -= rhs;
		positive = !positive;
	}
	else {
		int temp;
		for (int i = 0; i < data_.size(); i++)
		{
			temp = data_[i] + rhs.ReadFrom(i) + temp;
			data_[i] = temp % base;
			temp /= base;
		}
		if (temp > 0) {
			data_.push_back(temp);
		}
	}
	return *this;
}

Long_int Long_int::operator-=( Long_int rhs) {
	if (positive && !rhs.IsPositive()|| !positive && rhs.IsPositive()) {
		positive = !positive;
		*this += rhs;
		positive = !positive;
	}
	else if (rhs.IsPositive()) {
		if (data_.size() < rhs.ReadFrom().size() ||
			(data_.size() == rhs.ReadFrom().size() && data_.back() < rhs.ReadFrom(data_.size() - 1))) {
			positive = !positive;
			std::swap(*this, rhs);
		}
		int temp;
		for (int i = rhs.ReadFrom().size() - 1; i >= 0; i--)
		{
			temp = data_[i] - rhs.ReadFrom(i);
			if (temp < 0) {
				--data_[i + 1];
				data_[i] = -temp;
			}
			else {
				data_[i] = temp;
			}
		}
		while (data_.size() > 1 && data_.back() == 0)
			data_.pop_back();
	}
	return *this;
}

Long_int Long_int::operator*=(Long_int rhs) {

	return *this;
}

Long_int Long_int::operator*=(int rhs) {

	return *this;
}

Long_int operator+(Long_int& lhs, Long_int& rhs) {
	return (Long_int(lhs) += rhs);
}

Long_int operator-(Long_int& lhs, Long_int& rhs) {
	return (Long_int(lhs) -= rhs);
}

Long_int operator*(Long_int& lhs, Long_int& rhs) {
	return (Long_int(lhs) *= rhs);
}
