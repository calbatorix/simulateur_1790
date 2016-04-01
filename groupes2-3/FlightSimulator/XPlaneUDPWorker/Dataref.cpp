#include "Dataref.h"

Dataref::Dataref(const QString& path, int freq) {
	this->
	this->m_rrefFreq=freq ;
}

Dataref::Dataref(int iId, int aId, bool input) {
	this->m_instrumentId=iId;
	this->m_instrumentAxis=aId;
	this->
}

Dataref::Dataref(const QString& input, const QString& output, float scale, float offset) {
	this->m_sourceName =input ;
	this->m_targetName= output ;
	this->m_scale=scale;
	this->m_offset=offset;
}


void bindToInstrument(int iId, int aId, float scale, float offset) {

}

void bindToDigitalIo(const QString& name, float scale, float offset) {

}

void bindToAnalogIo(const QString& name, float scale, float offset) {

}


QByteArray xplaneRrefRequest() const {

}

QByteArray xplaneRrefStop() const {

}

QByteArray xplaneDref()(float value) const {

}


int id() const {

}


QString sourceName() const {

}

QString targetName() const {

} 


int instrumentId() const {

}

int instrumentAxis() const {

}

float scale() const {

}

float offset() const {
	
}


float lastValue() const {

}

void setLastValue(float v) {

}


bool Dataref::isRref() const {
	if (this->m_source=="RREF")
		return true ;
	return false ;
}

bool Dataref::isRrefQfi() const {
	if (this.isRref())
		if (this->m_target=="QFI")
			return true ;
	return false ;
}

bool Dataref::isRrefDigital() const {
	if (this.isRref())
		if (this->m_target=="TOR")
			return true ;
	return false ;
}

bool Dataref::isRrefAnalog() const {
	if (this.isRref())
		if (this->m_target=="ANA")
			return true ;
	return false ;
}


bool Dataref::Dref() const {
	if (this->m_target=="DREF")
		return true ;
	return false ;
}

bool Dataref::isDrefDigital() const {
	if (this.isDref())
		if (this->m_source=="TOR")
			return true ;
	return false ;
}

bool Dataref::isDrefAnalog() const {
	if (this.isDref())
		if (this->m_source=="ANA")
			return true ;
	return false ;
}


bool Dataref::isDigitalQfiInput() const {
	if (this->m_source=="TOR")
		if (this->m_target=="QFI")
			return true ;
	return false ;
}

bool Dataref::isAnalogQfiInput() const {
	if (this->m_source=="ANA")
		if (this->m_target=="QFI")
			return true ;
	return false ;
}

bool Dataref::isDigitalQfiOutput() const {
	if (this->m_source=="QFI")
		if (this->m_target=="TOR")
			return true ;
	return false ;
}

bool Dataref::isDigitalToDigital() const {
	if (this->m_source=="TOR")
		if (this->m_target=="TOR")
			return true ;
	return false ;
}


float scaled(float value) const {

}

QByteArray xplaneRref(int freq) const {

}