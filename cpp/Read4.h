#pragma once
class Read4 {
private:
	/*
	The API: int read4(char *buf) reads 4 characters at a time from a file.
	The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
	By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
	*/
	int read4(char *buf);

	int readPos = 0;
	int writePos = 0;
	char buff[4];

public:
	/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
	int read(char *buf, int n) {
		int t = read4(buf);
		if (t >= n) return n;
		if (t < 4) return t;
		return 4 + read(buf + 4, n - 4);
	}

	//Call multiple times
	int readII(char *buf, int n) {
		for (int i = 0; i < n; i++) {
			if (readPos == writePos) {
				writePos = read4(buff);
				readPos = 0;
				if (writePos == 0) return i;
			}
			buf[i] = buff[readPos++];
		}
		return n;
	}
};