#pragma once
# include <algorithm>
# include <string>
# include <array>
# include <utility>
# include <cctype>
# include <stdlib.h>
# include <iostream>

class Blowfish
{
private:
  union Word{
    char bytes[4];
    unsigned long toE;
  };

public:
  Blowfish(const std::string &);
  ~Blowfish();

private:
  Blowfish(const Blowfish &){}
  Blowfish &operator=(const Blowfish &){return *this;}

private:
  unsigned long Round(unsigned long) noexcept;
  void		to64(std::array<unsigned char, 8>&, std::pair<Word, Word>&) noexcept;
  void		from64(std::array<unsigned char, 8>&, std::pair<Word, Word>&) noexcept;

public:
  std::string	Encrypt(const std::string&) noexcept;
  std::string	Decrypt(const std::string&);
  void	Encrypt(unsigned long &, unsigned long &) noexcept;
  void	Decrypt(unsigned long &, unsigned long &) noexcept;
  void	Init(const std::string &) noexcept;

private:
  void	InitP(const std::string &) noexcept;
  void	EncryptPS() noexcept;

private:
  static const std::array<unsigned long, 18>			_PBOX;
  static const std::array<std::array<unsigned long, 256>, 4>	_SBOX;

private:
  std::array<unsigned long, 18>			_P;
  std::array<std::array<unsigned long, 256>, 4>	_S;
};
