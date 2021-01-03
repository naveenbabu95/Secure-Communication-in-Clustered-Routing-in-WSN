//
// Generated file, do not edit! Created by nedtool 4.6 from leach_message.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "leach_message_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(node2headMsg);

node2headMsg::node2headMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    this->source_var = 0;
    this->posX_var = 0;
    this->posY_var = 0;
    this->die_var = 0;
    this->battery_var = 0;
    this->temperature_var = 0;
}

node2headMsg::node2headMsg(const node2headMsg& other) : ::cMessage(other)
{
    copy(other);
}

node2headMsg::~node2headMsg()
{
}

node2headMsg& node2headMsg::operator=(const node2headMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void node2headMsg::copy(const node2headMsg& other)
{
    this->source_var = other.source_var;
    this->posX_var = other.posX_var;
    this->posY_var = other.posY_var;
    this->die_var = other.die_var;
    this->battery_var = other.battery_var;
    this->temperature_var = other.temperature_var;
}

void node2headMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->posX_var);
    doPacking(b,this->posY_var);
    doPacking(b,this->die_var);
    doPacking(b,this->battery_var);
    doPacking(b,this->temperature_var);
}

void node2headMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->posX_var);
    doUnpacking(b,this->posY_var);
    doUnpacking(b,this->die_var);
    doUnpacking(b,this->battery_var);
    doUnpacking(b,this->temperature_var);
}

int node2headMsg::getSource() const
{
    return source_var;
}

void node2headMsg::setSource(int source)
{
    this->source_var = source;
}

int node2headMsg::getPosX() const
{
    return posX_var;
}

void node2headMsg::setPosX(int posX)
{
    this->posX_var = posX;
}

int node2headMsg::getPosY() const
{
    return posY_var;
}

void node2headMsg::setPosY(int posY)
{
    this->posY_var = posY;
}

bool node2headMsg::getDie() const
{
    return die_var;
}

void node2headMsg::setDie(bool die)
{
    this->die_var = die;
}

double node2headMsg::getBattery() const
{
    return battery_var;
}

void node2headMsg::setBattery(double battery)
{
    this->battery_var = battery;
}

const char * node2headMsg::getTemperature() const
{
    return temperature_var.c_str();
}

void node2headMsg::setTemperature(const char * temperature)
{
    this->temperature_var = temperature;
}

class node2headMsgDescriptor : public cClassDescriptor
{
  public:
    node2headMsgDescriptor();
    virtual ~node2headMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(node2headMsgDescriptor);

node2headMsgDescriptor::node2headMsgDescriptor() : cClassDescriptor("node2headMsg", "cMessage")
{
}

node2headMsgDescriptor::~node2headMsgDescriptor()
{
}

bool node2headMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<node2headMsg *>(obj)!=NULL;
}

const char *node2headMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int node2headMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int node2headMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *node2headMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "posX",
        "posY",
        "die",
        "battery",
        "temperature",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int node2headMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "posX")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "posY")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "die")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "battery")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "temperature")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *node2headMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "bool",
        "double",
        "string",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *node2headMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int node2headMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    node2headMsg *pp = (node2headMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string node2headMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    node2headMsg *pp = (node2headMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return long2string(pp->getPosX());
        case 2: return long2string(pp->getPosY());
        case 3: return bool2string(pp->getDie());
        case 4: return double2string(pp->getBattery());
        case 5: return oppstring2string(pp->getTemperature());
        default: return "";
    }
}

bool node2headMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    node2headMsg *pp = (node2headMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setPosX(string2long(value)); return true;
        case 2: pp->setPosY(string2long(value)); return true;
        case 3: pp->setDie(string2bool(value)); return true;
        case 4: pp->setBattery(string2double(value)); return true;
        case 5: pp->setTemperature((value)); return true;
        default: return false;
    }
}

const char *node2headMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *node2headMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    node2headMsg *pp = (node2headMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(head2baseMsg);

head2baseMsg::head2baseMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    this->die_var = 0;
    this->source_var = 0;
    this->posX_var = 0;
    this->posY_var = 0;
    this->mes_var = 0;
    this->dieCount_var = 0;
    this->totalExpendedEnergy_var = 0.0;
}

head2baseMsg::head2baseMsg(const head2baseMsg& other) : ::cMessage(other)
{
    copy(other);
}

head2baseMsg::~head2baseMsg()
{
}

head2baseMsg& head2baseMsg::operator=(const head2baseMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void head2baseMsg::copy(const head2baseMsg& other)
{
    this->die_var = other.die_var;
    this->source_var = other.source_var;
    this->posX_var = other.posX_var;
    this->posY_var = other.posY_var;
    this->mes_var = other.mes_var;
    this->dieCount_var = other.dieCount_var;
    this->aggregatedData_var = other.aggregatedData_var;
    this->totalExpendedEnergy_var = other.totalExpendedEnergy_var;
}

void head2baseMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->die_var);
    doPacking(b,this->source_var);
    doPacking(b,this->posX_var);
    doPacking(b,this->posY_var);
    doPacking(b,this->mes_var);
    doPacking(b,this->dieCount_var);
    doPacking(b,this->aggregatedData_var);
    doPacking(b,this->totalExpendedEnergy_var);
}

void head2baseMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->die_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->posX_var);
    doUnpacking(b,this->posY_var);
    doUnpacking(b,this->mes_var);
    doUnpacking(b,this->dieCount_var);
    doUnpacking(b,this->aggregatedData_var);
    doUnpacking(b,this->totalExpendedEnergy_var);
}

bool head2baseMsg::getDie() const
{
    return die_var;
}

void head2baseMsg::setDie(bool die)
{
    this->die_var = die;
}

int head2baseMsg::getSource() const
{
    return source_var;
}

void head2baseMsg::setSource(int source)
{
    this->source_var = source;
}

int head2baseMsg::getPosX() const
{
    return posX_var;
}

void head2baseMsg::setPosX(int posX)
{
    this->posX_var = posX;
}

int head2baseMsg::getPosY() const
{
    return posY_var;
}

void head2baseMsg::setPosY(int posY)
{
    this->posY_var = posY;
}

const char * head2baseMsg::getMes() const
{
    return mes_var.c_str();
}

void head2baseMsg::setMes(const char * mes)
{
    this->mes_var = mes;
}

int head2baseMsg::getDieCount() const
{
    return dieCount_var;
}

void head2baseMsg::setDieCount(int dieCount)
{
    this->dieCount_var = dieCount;
}

mapForData& head2baseMsg::getAggregatedData()
{
    return aggregatedData_var;
}

void head2baseMsg::setAggregatedData(const mapForData& aggregatedData)
{
    this->aggregatedData_var = aggregatedData;
}

double head2baseMsg::getTotalExpendedEnergy() const
{
    return totalExpendedEnergy_var;
}

void head2baseMsg::setTotalExpendedEnergy(double totalExpendedEnergy)
{
    this->totalExpendedEnergy_var = totalExpendedEnergy;
}

class head2baseMsgDescriptor : public cClassDescriptor
{
  public:
    head2baseMsgDescriptor();
    virtual ~head2baseMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(head2baseMsgDescriptor);

head2baseMsgDescriptor::head2baseMsgDescriptor() : cClassDescriptor("head2baseMsg", "cMessage")
{
}

head2baseMsgDescriptor::~head2baseMsgDescriptor()
{
}

bool head2baseMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<head2baseMsg *>(obj)!=NULL;
}

const char *head2baseMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int head2baseMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int head2baseMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *head2baseMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "die",
        "source",
        "posX",
        "posY",
        "mes",
        "dieCount",
        "aggregatedData",
        "totalExpendedEnergy",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int head2baseMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "die")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "posX")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "posY")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "mes")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "dieCount")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "aggregatedData")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalExpendedEnergy")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *head2baseMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "int",
        "int",
        "string",
        "int",
        "mapForData",
        "double",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *head2baseMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int head2baseMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    head2baseMsg *pp = (head2baseMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string head2baseMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    head2baseMsg *pp = (head2baseMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getDie());
        case 1: return long2string(pp->getSource());
        case 2: return long2string(pp->getPosX());
        case 3: return long2string(pp->getPosY());
        case 4: return oppstring2string(pp->getMes());
        case 5: return long2string(pp->getDieCount());
        case 6: {std::stringstream out; out << pp->getAggregatedData(); return out.str();}
        case 7: return double2string(pp->getTotalExpendedEnergy());
        default: return "";
    }
}

bool head2baseMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    head2baseMsg *pp = (head2baseMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setDie(string2bool(value)); return true;
        case 1: pp->setSource(string2long(value)); return true;
        case 2: pp->setPosX(string2long(value)); return true;
        case 3: pp->setPosY(string2long(value)); return true;
        case 4: pp->setMes((value)); return true;
        case 5: pp->setDieCount(string2long(value)); return true;
        case 7: pp->setTotalExpendedEnergy(string2double(value)); return true;
        default: return false;
    }
}

const char *head2baseMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 6: return opp_typename(typeid(mapForData));
        default: return NULL;
    };
}

void *head2baseMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    head2baseMsg *pp = (head2baseMsg *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getAggregatedData()); break;
        default: return NULL;
    }
}

Register_Class(broadcastMsg);

broadcastMsg::broadcastMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    this->posX_var = 0;
    this->posY_var = 0;
    this->color_var = 0;
    this->chFullPath_var = 0;
    this->CHNodeNo_var = 0;
}

broadcastMsg::broadcastMsg(const broadcastMsg& other) : ::cMessage(other)
{
    copy(other);
}

broadcastMsg::~broadcastMsg()
{
}

broadcastMsg& broadcastMsg::operator=(const broadcastMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void broadcastMsg::copy(const broadcastMsg& other)
{
    this->posX_var = other.posX_var;
    this->posY_var = other.posY_var;
    this->color_var = other.color_var;
    this->chFullPath_var = other.chFullPath_var;
    this->CHNodeNo_var = other.CHNodeNo_var;
}

void broadcastMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->posX_var);
    doPacking(b,this->posY_var);
    doPacking(b,this->color_var);
    doPacking(b,this->chFullPath_var);
    doPacking(b,this->CHNodeNo_var);
}

void broadcastMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->posX_var);
    doUnpacking(b,this->posY_var);
    doUnpacking(b,this->color_var);
    doUnpacking(b,this->chFullPath_var);
    doUnpacking(b,this->CHNodeNo_var);
}

int broadcastMsg::getPosX() const
{
    return posX_var;
}

void broadcastMsg::setPosX(int posX)
{
    this->posX_var = posX;
}

int broadcastMsg::getPosY() const
{
    return posY_var;
}

void broadcastMsg::setPosY(int posY)
{
    this->posY_var = posY;
}

const char * broadcastMsg::getColor() const
{
    return color_var.c_str();
}

void broadcastMsg::setColor(const char * color)
{
    this->color_var = color;
}

const char * broadcastMsg::getChFullPath() const
{
    return chFullPath_var.c_str();
}

void broadcastMsg::setChFullPath(const char * chFullPath)
{
    this->chFullPath_var = chFullPath;
}

int broadcastMsg::getCHNodeNo() const
{
    return CHNodeNo_var;
}

void broadcastMsg::setCHNodeNo(int CHNodeNo)
{
    this->CHNodeNo_var = CHNodeNo;
}

class broadcastMsgDescriptor : public cClassDescriptor
{
  public:
    broadcastMsgDescriptor();
    virtual ~broadcastMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(broadcastMsgDescriptor);

broadcastMsgDescriptor::broadcastMsgDescriptor() : cClassDescriptor("broadcastMsg", "cMessage")
{
}

broadcastMsgDescriptor::~broadcastMsgDescriptor()
{
}

bool broadcastMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<broadcastMsg *>(obj)!=NULL;
}

const char *broadcastMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int broadcastMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int broadcastMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *broadcastMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "posX",
        "posY",
        "color",
        "chFullPath",
        "CHNodeNo",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int broadcastMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "posX")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "posY")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "color")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "chFullPath")==0) return base+3;
    if (fieldName[0]=='C' && strcmp(fieldName, "CHNodeNo")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *broadcastMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *broadcastMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int broadcastMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    broadcastMsg *pp = (broadcastMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string broadcastMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    broadcastMsg *pp = (broadcastMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPosX());
        case 1: return long2string(pp->getPosY());
        case 2: return oppstring2string(pp->getColor());
        case 3: return oppstring2string(pp->getChFullPath());
        case 4: return long2string(pp->getCHNodeNo());
        default: return "";
    }
}

bool broadcastMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    broadcastMsg *pp = (broadcastMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPosX(string2long(value)); return true;
        case 1: pp->setPosY(string2long(value)); return true;
        case 2: pp->setColor((value)); return true;
        case 3: pp->setChFullPath((value)); return true;
        case 4: pp->setCHNodeNo(string2long(value)); return true;
        default: return false;
    }
}

const char *broadcastMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *broadcastMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    broadcastMsg *pp = (broadcastMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(bsInitbroadcastMsg);

bsInitbroadcastMsg::bsInitbroadcastMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    for (unsigned int i=0; i<48; i++)
        this->publicKey_var[i] = 0;
}

bsInitbroadcastMsg::bsInitbroadcastMsg(const bsInitbroadcastMsg& other) : ::cMessage(other)
{
    copy(other);
}

bsInitbroadcastMsg::~bsInitbroadcastMsg()
{
}

bsInitbroadcastMsg& bsInitbroadcastMsg::operator=(const bsInitbroadcastMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void bsInitbroadcastMsg::copy(const bsInitbroadcastMsg& other)
{
    for (unsigned int i=0; i<48; i++)
        this->publicKey_var[i] = other.publicKey_var[i];
}

void bsInitbroadcastMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->publicKey_var,48);
}

void bsInitbroadcastMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->publicKey_var,48);
}

unsigned int bsInitbroadcastMsg::getPublicKeyArraySize() const
{
    return 48;
}

uint8_t bsInitbroadcastMsg::getPublicKey(unsigned int k) const
{
    if (k>=48) throw cRuntimeError("Array of size 48 indexed by %lu", (unsigned long)k);
    return publicKey_var[k];
}

void bsInitbroadcastMsg::setPublicKey(unsigned int k, uint8_t publicKey)
{
    if (k>=48) throw cRuntimeError("Array of size 48 indexed by %lu", (unsigned long)k);
    this->publicKey_var[k] = publicKey;
}

class bsInitbroadcastMsgDescriptor : public cClassDescriptor
{
  public:
    bsInitbroadcastMsgDescriptor();
    virtual ~bsInitbroadcastMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(bsInitbroadcastMsgDescriptor);

bsInitbroadcastMsgDescriptor::bsInitbroadcastMsgDescriptor() : cClassDescriptor("bsInitbroadcastMsg", "cMessage")
{
}

bsInitbroadcastMsgDescriptor::~bsInitbroadcastMsgDescriptor()
{
}

bool bsInitbroadcastMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<bsInitbroadcastMsg *>(obj)!=NULL;
}

const char *bsInitbroadcastMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int bsInitbroadcastMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int bsInitbroadcastMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *bsInitbroadcastMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "publicKey",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int bsInitbroadcastMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "publicKey")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *bsInitbroadcastMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *bsInitbroadcastMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int bsInitbroadcastMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    bsInitbroadcastMsg *pp = (bsInitbroadcastMsg *)object; (void)pp;
    switch (field) {
        case 0: return 48;
        default: return 0;
    }
}

std::string bsInitbroadcastMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    bsInitbroadcastMsg *pp = (bsInitbroadcastMsg *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPublicKey(i));
        default: return "";
    }
}

bool bsInitbroadcastMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    bsInitbroadcastMsg *pp = (bsInitbroadcastMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPublicKey(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *bsInitbroadcastMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *bsInitbroadcastMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    bsInitbroadcastMsg *pp = (bsInitbroadcastMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(littleBroMsg);

littleBroMsg::littleBroMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    this->posX_var = 0;
    this->posY_var = 0;
    this->chNo_var = 0;
    this->chPosX_var = 0;
    this->chPosY_var = 0;
    this->chFullPath_var = 0;
    this->color_var = 0;
}

littleBroMsg::littleBroMsg(const littleBroMsg& other) : ::cMessage(other)
{
    copy(other);
}

littleBroMsg::~littleBroMsg()
{
}

littleBroMsg& littleBroMsg::operator=(const littleBroMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void littleBroMsg::copy(const littleBroMsg& other)
{
    this->posX_var = other.posX_var;
    this->posY_var = other.posY_var;
    this->chNo_var = other.chNo_var;
    this->chPosX_var = other.chPosX_var;
    this->chPosY_var = other.chPosY_var;
    this->chFullPath_var = other.chFullPath_var;
    this->color_var = other.color_var;
}

void littleBroMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->posX_var);
    doPacking(b,this->posY_var);
    doPacking(b,this->chNo_var);
    doPacking(b,this->chPosX_var);
    doPacking(b,this->chPosY_var);
    doPacking(b,this->chFullPath_var);
    doPacking(b,this->color_var);
}

void littleBroMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->posX_var);
    doUnpacking(b,this->posY_var);
    doUnpacking(b,this->chNo_var);
    doUnpacking(b,this->chPosX_var);
    doUnpacking(b,this->chPosY_var);
    doUnpacking(b,this->chFullPath_var);
    doUnpacking(b,this->color_var);
}

int littleBroMsg::getPosX() const
{
    return posX_var;
}

void littleBroMsg::setPosX(int posX)
{
    this->posX_var = posX;
}

int littleBroMsg::getPosY() const
{
    return posY_var;
}

void littleBroMsg::setPosY(int posY)
{
    this->posY_var = posY;
}

int littleBroMsg::getChNo() const
{
    return chNo_var;
}

void littleBroMsg::setChNo(int chNo)
{
    this->chNo_var = chNo;
}

int littleBroMsg::getChPosX() const
{
    return chPosX_var;
}

void littleBroMsg::setChPosX(int chPosX)
{
    this->chPosX_var = chPosX;
}

int littleBroMsg::getChPosY() const
{
    return chPosY_var;
}

void littleBroMsg::setChPosY(int chPosY)
{
    this->chPosY_var = chPosY;
}

const char * littleBroMsg::getChFullPath() const
{
    return chFullPath_var.c_str();
}

void littleBroMsg::setChFullPath(const char * chFullPath)
{
    this->chFullPath_var = chFullPath;
}

const char * littleBroMsg::getColor() const
{
    return color_var.c_str();
}

void littleBroMsg::setColor(const char * color)
{
    this->color_var = color;
}

class littleBroMsgDescriptor : public cClassDescriptor
{
  public:
    littleBroMsgDescriptor();
    virtual ~littleBroMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(littleBroMsgDescriptor);

littleBroMsgDescriptor::littleBroMsgDescriptor() : cClassDescriptor("littleBroMsg", "cMessage")
{
}

littleBroMsgDescriptor::~littleBroMsgDescriptor()
{
}

bool littleBroMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<littleBroMsg *>(obj)!=NULL;
}

const char *littleBroMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int littleBroMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int littleBroMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *littleBroMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "posX",
        "posY",
        "chNo",
        "chPosX",
        "chPosY",
        "chFullPath",
        "color",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int littleBroMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "posX")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "posY")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "chNo")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "chPosX")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "chPosY")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "chFullPath")==0) return base+5;
    if (fieldName[0]=='c' && strcmp(fieldName, "color")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *littleBroMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "string",
        "string",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *littleBroMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int littleBroMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    littleBroMsg *pp = (littleBroMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string littleBroMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    littleBroMsg *pp = (littleBroMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPosX());
        case 1: return long2string(pp->getPosY());
        case 2: return long2string(pp->getChNo());
        case 3: return long2string(pp->getChPosX());
        case 4: return long2string(pp->getChPosY());
        case 5: return oppstring2string(pp->getChFullPath());
        case 6: return oppstring2string(pp->getColor());
        default: return "";
    }
}

bool littleBroMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    littleBroMsg *pp = (littleBroMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPosX(string2long(value)); return true;
        case 1: pp->setPosY(string2long(value)); return true;
        case 2: pp->setChNo(string2long(value)); return true;
        case 3: pp->setChPosX(string2long(value)); return true;
        case 4: pp->setChPosY(string2long(value)); return true;
        case 5: pp->setChFullPath((value)); return true;
        case 6: pp->setColor((value)); return true;
        default: return false;
    }
}

const char *littleBroMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *littleBroMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    littleBroMsg *pp = (littleBroMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(Node2BaseMsg);

Node2BaseMsg::Node2BaseMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    this->source_var = 0;
    this->posX_var = 0;
    this->posY_var = 0;
    this->battery_var = 0;
    this->hash_var = 0;
    this->purpose_var = 0;
    this->timestamp_var = 0;
    for (unsigned int i=0; i<48; i++)
        this->nodepublickey_var[i] = 0;
}

Node2BaseMsg::Node2BaseMsg(const Node2BaseMsg& other) : ::cMessage(other)
{
    copy(other);
}

Node2BaseMsg::~Node2BaseMsg()
{
}

Node2BaseMsg& Node2BaseMsg::operator=(const Node2BaseMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Node2BaseMsg::copy(const Node2BaseMsg& other)
{
    this->source_var = other.source_var;
    this->posX_var = other.posX_var;
    this->posY_var = other.posY_var;
    this->battery_var = other.battery_var;
    this->hash_var = other.hash_var;
    this->purpose_var = other.purpose_var;
    this->timestamp_var = other.timestamp_var;
    for (unsigned int i=0; i<48; i++)
        this->nodepublickey_var[i] = other.nodepublickey_var[i];
}

void Node2BaseMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->posX_var);
    doPacking(b,this->posY_var);
    doPacking(b,this->battery_var);
    doPacking(b,this->hash_var);
    doPacking(b,this->purpose_var);
    doPacking(b,this->timestamp_var);
    doPacking(b,this->nodepublickey_var,48);
}

void Node2BaseMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->posX_var);
    doUnpacking(b,this->posY_var);
    doUnpacking(b,this->battery_var);
    doUnpacking(b,this->hash_var);
    doUnpacking(b,this->purpose_var);
    doUnpacking(b,this->timestamp_var);
    doUnpacking(b,this->nodepublickey_var,48);
}

int Node2BaseMsg::getSource() const
{
    return source_var;
}

void Node2BaseMsg::setSource(int source)
{
    this->source_var = source;
}

int Node2BaseMsg::getPosX() const
{
    return posX_var;
}

void Node2BaseMsg::setPosX(int posX)
{
    this->posX_var = posX;
}

int Node2BaseMsg::getPosY() const
{
    return posY_var;
}

void Node2BaseMsg::setPosY(int posY)
{
    this->posY_var = posY;
}

double Node2BaseMsg::getBattery() const
{
    return battery_var;
}

void Node2BaseMsg::setBattery(double battery)
{
    this->battery_var = battery;
}

const char * Node2BaseMsg::getHash() const
{
    return hash_var.c_str();
}

void Node2BaseMsg::setHash(const char * hash)
{
    this->hash_var = hash;
}

const char * Node2BaseMsg::getPurpose() const
{
    return purpose_var.c_str();
}

void Node2BaseMsg::setPurpose(const char * purpose)
{
    this->purpose_var = purpose;
}

const char * Node2BaseMsg::getTimestamp() const
{
    return timestamp_var.c_str();
}

void Node2BaseMsg::setTimestamp(const char * timestamp)
{
    this->timestamp_var = timestamp;
}

unsigned int Node2BaseMsg::getNodepublickeyArraySize() const
{
    return 48;
}

uint8_t Node2BaseMsg::getNodepublickey(unsigned int k) const
{
    if (k>=48) throw cRuntimeError("Array of size 48 indexed by %lu", (unsigned long)k);
    return nodepublickey_var[k];
}

void Node2BaseMsg::setNodepublickey(unsigned int k, uint8_t nodepublickey)
{
    if (k>=48) throw cRuntimeError("Array of size 48 indexed by %lu", (unsigned long)k);
    this->nodepublickey_var[k] = nodepublickey;
}

class Node2BaseMsgDescriptor : public cClassDescriptor
{
  public:
    Node2BaseMsgDescriptor();
    virtual ~Node2BaseMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(Node2BaseMsgDescriptor);

Node2BaseMsgDescriptor::Node2BaseMsgDescriptor() : cClassDescriptor("Node2BaseMsg", "cMessage")
{
}

Node2BaseMsgDescriptor::~Node2BaseMsgDescriptor()
{
}

bool Node2BaseMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Node2BaseMsg *>(obj)!=NULL;
}

const char *Node2BaseMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Node2BaseMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int Node2BaseMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *Node2BaseMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "posX",
        "posY",
        "battery",
        "hash",
        "purpose",
        "timestamp",
        "nodepublickey",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int Node2BaseMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "posX")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "posY")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "battery")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hash")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "purpose")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodepublickey")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Node2BaseMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "double",
        "string",
        "string",
        "string",
        "uint8_t",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *Node2BaseMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int Node2BaseMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Node2BaseMsg *pp = (Node2BaseMsg *)object; (void)pp;
    switch (field) {
        case 7: return 48;
        default: return 0;
    }
}

std::string Node2BaseMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Node2BaseMsg *pp = (Node2BaseMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return long2string(pp->getPosX());
        case 2: return long2string(pp->getPosY());
        case 3: return double2string(pp->getBattery());
        case 4: return oppstring2string(pp->getHash());
        case 5: return oppstring2string(pp->getPurpose());
        case 6: return oppstring2string(pp->getTimestamp());
        case 7: return ulong2string(pp->getNodepublickey(i));
        default: return "";
    }
}

bool Node2BaseMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Node2BaseMsg *pp = (Node2BaseMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setPosX(string2long(value)); return true;
        case 2: pp->setPosY(string2long(value)); return true;
        case 3: pp->setBattery(string2double(value)); return true;
        case 4: pp->setHash((value)); return true;
        case 5: pp->setPurpose((value)); return true;
        case 6: pp->setTimestamp((value)); return true;
        case 7: pp->setNodepublickey(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *Node2BaseMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *Node2BaseMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Node2BaseMsg *pp = (Node2BaseMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


