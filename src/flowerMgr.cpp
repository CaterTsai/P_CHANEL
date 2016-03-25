#include "flowerMgr.h"

#pragma region flower
//-------------------------------------------------
flowerMgr::flower::flower(eFlowerType etype)
	:_eType(etype)
	,_isDie(false)
	,_AnimStart(false)
{
	_degree = ofRandom(0, 360);
	_vec.set(0, ofGetHeight()/ofRandom(cFLOWER_FELLINGSPEED.first, cFLOWER_FELLINGSPEED.second));
	_rVec = ofRandom(30, 90) * (ofRandom(-1, 1)>0?-1:1);
	_fscale = ofRandom(0.45, 0.6);
	_pos.set(ofRandomWidth(), -_fscale * cFLOWER_RECT.height);

	_animPrec.setDuration(cFLOWER_DURATION);
	_animPrec.setCurve(AnimCurve::LINEAR);
}

//-------------------------------------------------
void flowerMgr::flower::update(float fdelta)
{
	if(_isDie)
	{
		return;
	}

	if(_AnimStart)
	{
		_animPrec.update(fdelta);
		if(_animPrec.hasFinishedAnimating() && _animPrec.getPercentDone() == 1.0)
		{
			_isDie = true;
		}
	}
	else
	{
		_pos += _vec * fdelta;
		_degree += _rVec * fdelta;
		if(_degree > 360.0f)
		{
			_degree -= 360.0f;
		}

		if(_pos.y > ofGetHeight() + _fscale * cFLOWER_RECT.height)
		{
			_isDie = true;
		}
	}
}				

//-------------------------------------------------
bool flowerMgr::flower::startAnim()
{
	if(!_AnimStart)
	{
		_AnimStart = true;
		_animPrec.animateFromTo(0.0, 1.0);
		return true;
	}
	return false;
}

//-------------------------------------------------
bool flowerMgr::flower::getDie()
{
	return _isDie;
}

//-------------------------------------------------
bool flowerMgr::flower::getAnimStart()
{
	return _AnimStart;
}

//-------------------------------------------------
float flowerMgr::flower::getRotate()
{
	return _degree;
}

//-------------------------------------------------
float flowerMgr::flower::getScale()
{
	return _fscale;
}

//-------------------------------------------------
float flowerMgr::flower::getAnimPrec()
{
	if(_AnimStart)
	{
		return _animPrec.getCurrentValue();
	}
	else
	{
		return 0.0;
	}
	
}

//-------------------------------------------------
ofVec2f flowerMgr::flower::getPos()
{
	return _pos;
}

//-------------------------------------------------
eFlowerType flowerMgr::flower::getType()
{
	return _eType;
}
#pragma endregion

#pragma region flowerMgr
//-------------------------------------------------
void flowerMgr::setup()
{
	bool isSuccess_ = true;

	//Load flower image
	isSuccess_ &= loadFlowerSequence(eFlower_1, "flower_1");
	isSuccess_ &= loadFlowerSequence(eFlower_2, "flower_2");

	_flowerAudio.loadSound("audios/flower.mp3");
	_flowerAudio.setLoop(false);
	_flowerAudio.setMultiPlay(true);

	_animAlpha.setDuration(2.0);
	_animAlpha.setRepeatType(AnimRepeat::PLAY_ONCE);

	_isSetup  = true;
}

//-------------------------------------------------
void flowerMgr::update(float fDelta, ofVec2f CtrlPos)
{
	if(!_isSetup)
	{
		return;
	}
	_animAlpha.update(fDelta);

	//Check all flower element
	auto Iter_ = _flowerList.begin();
	while(Iter_ != _flowerList.end())
	{
		Iter_->update(fDelta);

		if(_CanTrigger)
		{
			ofVec2f pos_ = Iter_->getPos();
			if(pos_.distance(CtrlPos) < cFLOWER_TRIGGER_DIST)
			{
				if(Iter_->startAnim())
				{
					_flowerAudio.play();
				}
				
			}
		}

		if(Iter_->getDie())
		{
			Iter_ = _flowerList.erase(Iter_);
		}
		else
		{
			Iter_++;
		}
	}

	//add new flower
	if(!_isStart)
	{
		return;
	}
	_fTimer -= fDelta;
	if(_fTimer <= 0.0f)
	{
		if(_flowerList.size() < cFLOWER_MAX_NUM)
		{
			flowerMgr::flower newFlower_( (ofRandom(-1, 1)> 0)?eFlower_1:eFlower_2);
			_flowerList.push_back(newFlower_);
		}
		_fTimer = ofRandom(1.0, 3.0);
		//_fTimer = 10;
	}
}

//-------------------------------------------------
void flowerMgr::draw()
{
	if(!_isSetup)
	{
		return;
	}

	ofPushStyle();
	ofSetColor(255, 255, 255, _animAlpha.getCurrentValue());
	{
		for(auto& Iter_ : _flowerList)
		{
			if(Iter_.getDie())
			{
				continue;
			}

			float scale_ = Iter_.getScale();
			auto pos_ = Iter_.getPos();
			float fdegree_ = Iter_.getRotate();
			eFlowerType eType_ = Iter_.getType();
			
			int frame_ = 0;
			if(_CanTrigger)
			{
				frame_ = static_cast<int>(Iter_.getAnimPrec() * _animMgr[eType_].size()) % _animMgr[eType_].size();
			}

			ofPushMatrix();
			ofTranslate(pos_);
			ofRotateZ(fdegree_);
			{
				float fwidth_ = cFLOWER_RECT.width * scale_;
				float fheight_ = cFLOWER_RECT.height * scale_;
				ofVec2f drawPos_(fwidth_ * -0.5, fheight_ * -0.5);
				_animMgr[eType_][frame_].draw(drawPos_, fwidth_, fheight_);
			}
			ofPopMatrix();
		}
	}
	ofPopStyle();
}

//-------------------------------------------------
void flowerMgr::start()
{
	if(!_isStart)
	{
		_isStart = true;
		_CanTrigger = false;
		_fTimer = 0.0f;

		_animAlpha.animateFromTo(0.0, 255.0);
	}
}

//-------------------------------------------------
void flowerMgr::stop()
{
	_isStart = false;
	_animAlpha.animateFromTo(255.0, 0.0);
}

//-------------------------------------------------
void flowerMgr::clear()
{
	stop();
	_flowerList.clear();
}

//-------------------------------------------------
void flowerMgr::setTriggerCheck(bool val)
{
	_CanTrigger = true;
}

//-------------------------------------------------
bool flowerMgr::loadFlowerSequence(eFlowerType eType, string strName)
{
	ofDirectory dir_("images/" + strName + "/");
	
	dir_.allowExt("png");
	dir_.listDir();

	if(dir_.numFiles() < 0)
	{
		return false;
	}
	else
	{
		vector<ofImage> imageList_;
		imageList_.resize(dir_.numFiles());
		_animMgr.insert(make_pair(eType, imageList_));

		for(int idx_ = 0; idx_ < dir_.numFiles(); ++idx_)
		{
			_animMgr[eType][idx_].loadImage(dir_.getPath(idx_));
		}

		ofLog(OF_LOG_NOTICE, "[flowerMgr]load flower sequence success :" + strName);
		return true;
	}
}
#pragma endregion
