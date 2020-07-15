#include<longint/longint.h>
#include<string>
#include<iomanip>
#include<algorithm>

LongInt::LongInt(const LongInt& Data_) :
	data_(Data_.data_),
	positive(Data_.positive)
{}

LongInt::LongInt(const std::vector<uint32_t>& Data_) :
	data_(Data_) 
{}


LongInt::LongInt(const std::vector<uint32_t>& Data_, bool Positive) :
	data_(Data_),
	positive(Positive)
{}

LongInt::~LongInt() {
	delete &data_;
	delete &positive;
}

bool LongInt::operator == (const LongInt& rhs) {
	if (data_.size() == rhs.data_.size()) {
		for (size_t i = 0; i < data_.size; i++) {
			if (data_[i] != rhs.data_[i])
				return false;
		}
		return true;
	}
	return false;
}
bool LongInt::operator != (const LongInt& rhs) {
	return !(*this == rhs);
}
bool LongInt::operator < (const LongInt& rhs) {
	if (data_.size() == rhs.data_.size()) {
		for (size_t i = 0; i < data_.size; i++) {
			if (data_[i] > rhs.data_[i])
				return false;
		}
		if (data_[data_.size()] == rhs.data_[data_.size()]) {
			return false;
		}
		return true;
	}
	if (data_.size() < rhs.data_.size()) {
		return true;
	}
	else {
		return false;
	}
}
bool LongInt::operator <= (const LongInt& rhs) {
	return !(*this > rhs);
}
bool LongInt::operator > (const LongInt& rhs) {
	if (data_.size() == rhs.data_.size()) {
		for (size_t i = 0; i < data_.size; i++) {
			if (data_[i] < rhs.data_[i])
				return false;
		}
		if (data_[data_.size()] == rhs.data_[data_.size()]) {
			return false;
		}
		return true;
	}
	if (data_.size() > rhs.data_.size()) {
		return true;
	}
	else {
		return false;
	}
}
bool LongInt::operator >= (const LongInt& rhs) {
	return !(*this < rhs);
}

void LongInt::operator=(LongInt LongInt) {
	data_ = LongInt.ReadFrom();
}

std::vector<uint32_t> LongInt::ReadFrom() const{
	return data_;
}

uint32_t LongInt::ReadFrom(int i)const {
	return data_[i];
}

bool LongInt::IsPositive() const {
	return positive;
}

std::istream& operator>>(std::istream& stream, LongInt& longint) {
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
	longint = LongInt(v);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const LongInt& LongInt) {
	std::string a;
	bool first = true;
	for (int i = (int)LongInt.ReadFrom().size() - 1; i >= 0; --i) {
		if (first) {
			stream << LongInt.ReadFrom(i);
			first = false;
		}
		else {
			stream << std::setfill('0') << std::setw(9) << LongInt.ReadFrom(i);
		}
	}
	return stream;
}

LongInt LongInt::operator+=(LongInt rhs) {
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

LongInt LongInt::operator-=( LongInt rhs) {
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

LongInt LongInt::operator*=(LongInt rhs) {
	for (int j: rhs.ReadFrom()){
		*this *= j;
	}
	if (!rhs.IsPositive()) {
		positive = !positive;
	}
	return *this;
}

LongInt LongInt::operator*=(int rhs) {
	if (!rhs>0) {
		positive = !positive;
	}
	int64_t  temp;
	for (int i = 0; i < data_.size(); i++)
	{
		temp = data_[i] + rhs + temp;
		data_[i] = temp % base;
		temp /= base;
	}
	if (temp > 0) {
		data_.push_back(temp);
	}
	return *this;
}

LongInt operator+(LongInt& lhs, LongInt& rhs) {
	return (LongInt(lhs) += rhs);
}

LongInt operator-(LongInt& lhs, LongInt& rhs) {
	return (LongInt(lhs) -= rhs);
}

LongInt operator*(LongInt& lhs, LongInt& rhs) {
	return (LongInt(lhs) *= rhs);
}
