#include "string.h"

namespace rain {
// class String
String::String(const char * str = nullptr) {
	if (str) {
		std::size_t len = strlen(str) + 1;
		content_ = new char[len];
		strncpy(content_, str, len);
		length_ = len - 1;
	} else {
		content_ = new char[1];
		*content_ = '\0';
	}
}

String::String(const String &&) noexcept {

}

String::String(const String& str) {
	std::size_t len = str.length_ + 1;
	content_ = new char[len];
	strncpy(content_, str.content_, len);
	length_ = len - 1;
}

inline
String& String::operator= (const String& str) {

	if (this == &str) {
		return *this;
	}

	delete[] content_;
	std::size_t len = str.length_ + 1;
	content_ = new char[len];
	strncpy(content_, str.content_, len);
	length_ = len - 1;
	return *this;
}

String::~String() {
	delete[] content_;
}

std::ostream& operator<< (std::ostream& os, const String& str) {
	printf("%s", str.content_);
	return os;
}

bool String::kmp(const char * substr) {

	int len = strlen(substr);

	if (len == 0) {
		return true;
	}

	if (len > length_) {
		return false;
	}

	// preprocess pattern string 
	std::unique_ptr<int[]> next(new int[len]);
	next[0] = -1;
	int k = -1;
	for (int i = 1; i < len; i++) {
		while (k >= 0 && substr[k + 1] != substr[i]) {
			k = next[k];
		}
		if (substr[k + 1] == substr[i]) {
			k = k + 1;
		}
		next[i] = k;
	}

	// match
	int j = -1;
	for (int i = 0; i < length_; i++) {
		while (j > -1 && substr[j + 1] != content_[i]) {
			j = next[j];
		}
		if (substr[j + 1] == content_[i]) {
			j++;
		}
		if (j + 1 == len) {
			return true;
		}
	}

	return false;
}
}




