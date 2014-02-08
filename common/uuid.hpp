#ifndef _BREW_LIB_UUID_H_
#define _BREW_LIB_UUID_H_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>	

#include "brew.hpp"

BEGIN_NAMESPACE(brew)

class uuid
{
public:
	uuid() { __uuid = gen(); }

   static boost::uuids::uuid	toUUID(const std::string & u) {
	   return boost::lexical_cast<boost::uuids::uuid>(u);
	}
   static std::string			to_string(const boost::uuids::uuid u) {
	   return boost::uuids::to_string(u);
	}
   static std::string			to_string() {
	   boost::uuids::random_generator gen;
	   boost::uuids::uuid u = gen();
	   return boost::uuids::to_string(u);
	}
   static boost::uuids::uuid	gen() {
	   boost::uuids::random_generator gen;
	   boost::uuids::uuid u = gen();
	   return u;
	}

   std::string	toString() {
		return to_string(__uuid);
	}

private:
   boost::uuids::uuid	__uuid;
};




END_NAMESPACE(brew)

#endif