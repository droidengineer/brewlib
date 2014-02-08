#ifndef _BREW_LIB_ENTITY_H_
#define _BREW_LIB_ENTITY_H_

#include <string>
#include "uuid.hpp"
#include "brew.hpp"

BEGIN_NAMESPACE(brew)
BEGIN_NAMESPACE(entity)

class Entity
{
public:
	const uuid id() const { return _uuid; }

protected:
	Entity() {
	}
	virtual ~Entity() { }

	const uuid toUUID() const { return _uuid; }
	virtual std::string toString() { return _uuid.toString(); }

	virtual void addAspect(Component & t) = 0;
	virtual void removeAspect(std::string & n) = 0;
	virtual void removeAspect(Component & c) = 0;
	virtual void updateAspectType(Component & t);
	virtual void handleMessage(MessageType) = 0;


private:
	 uuid	_uuid;
};

class Component
{
protected:
	virtual void startup() = 0;
	virtual void update() = 0;
	virtual void shutdown() = 0;
	virtual void handleMessage(MessageType);
};





END_NAMESPACE(entity)
END_NAMESPACE(brew)

#endif