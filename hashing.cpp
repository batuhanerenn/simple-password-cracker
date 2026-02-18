
#include "hashing.h"
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
using namespace std;

string md5(const string& input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.size(), digest);

    ostringstream oss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        oss << hex << setw(2) << setfill('0') << (int)digest[i];
    return oss.str();
}
