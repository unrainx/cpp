#ifndef RAIN_STRING_H__
#define RAIN_STRING_H__

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

namespace rain {

	class String final {

		friend std::ostream& operator<< (std::ostream&, const String&);

	private:
		char * content_;
		std::size_t length_ = 0;

	public:

		class iterator {
		private:
			char * ptr_;

		public:
			explicit iterator(char * ptr): ptr_(ptr) {  }

			bool operator!=(const iterator& iter) {
				return ptr_ != iter.ptr_;
			}

			void operator++() {
				ptr_++;
			}

			char& operator*() {
				return *ptr_;
			}
		};

		iterator begin() {
			return iterator(&content_[0]);
		}

		iterator end() {
			return iterator(&content_[0] + length_ + 1);
		}

		explicit String(const char *);

		explicit String(const String &&) noexcept;

		explicit String(const String&);

		String& operator= (const String&);

		~String();

		const char * c_str() const {
			return content_;
		}

		const std::size_t length() const {
			return length_;
		}

		bool kmp(const char *);

		bool include(const char * pattern) {
			return kmp(pattern);
		}

		bool include(const String& pattern) {
			return kmp(pattern.c_str());
		}

	};

}


#endif // !RAIN_STRING_H__
