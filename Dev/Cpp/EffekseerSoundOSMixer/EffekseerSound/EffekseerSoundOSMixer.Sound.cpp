﻿
//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "../EffekseerSoundOSMixer.h"
#include "EffekseerSoundOSMixer.SoundImplemented.h"
#include "EffekseerSoundOSMixer.SoundLoader.h"
#include "EffekseerSoundOSMixer.SoundPlayer.h"

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace EffekseerSound
{

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
Sound* Sound::Create(osm::Manager* soundManager)
{
	SoundImplemented* sound = new SoundImplemented();
	if (sound->Initialize(soundManager))
	{
		return sound;
	}
	return NULL;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
SoundImplemented::SoundImplemented()
	: m_manager(NULL)
	, m_mute(false)
{
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
SoundImplemented::~SoundImplemented()
{
	StopAll();
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
bool SoundImplemented::Initialize(osm::Manager* soundManager)
{
	m_manager = soundManager;

	return true;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::SetListener(const ::Effekseer::Vector3D& pos, const ::Effekseer::Vector3D& at, const ::Effekseer::Vector3D& up)
{
	using Vector3D = ::Effekseer::Vector3D;

	m_listener.position = pos;
	Vector3D::Sub(m_listener.forwardVector, at, pos);
	Vector3D::Normal(m_listener.forwardVector, m_listener.forwardVector);
	Vector3D::Normal(m_listener.upVector, up);
	Vector3D::Cross(m_listener.rightVector, m_listener.forwardVector, m_listener.upVector);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::Destroy()
{
	delete this;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::Update()
{
	for (auto it = m_instances.begin(); it != m_instances.end();)
	{
		if (!m_manager->IsPlaying(it->id))
		{
			it = m_instances.erase(it);
		}
		else
		{
			it++;
		}
	}
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
::Effekseer::SoundPlayer* SoundImplemented::CreateSoundPlayer()
{
	return new SoundPlayer(this);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
::Effekseer::SoundLoader* SoundImplemented::CreateSoundLoader(::Effekseer::FileInterface* fileInterface)
{
	return new SoundLoader(this, fileInterface);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::StopAll()
{
	m_manager->StopAll();
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::SetMute(bool mute)
{
	m_mute = mute;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::AddInstance(const Instance& instance)
{
	m_instances.push_back(instance);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::StopTag(::Effekseer::SoundTag tag)
{
	for (auto it = m_instances.begin(); it != m_instances.end(); it++)
	{
		if (it->tag == tag)
		{
			m_manager->Stop(it->id);
		}
	}
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::PauseTag(::Effekseer::SoundTag tag, bool pause)
{
	for (auto it = m_instances.begin(); it != m_instances.end(); it++)
	{
		if (it->tag == tag)
		{
			if (pause)
			{
				m_manager->Pause(it->id);
			}
			else
			{
				m_manager->Resume(it->id);
			}
		}
	}
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
bool SoundImplemented::CheckPlayingTag(::Effekseer::SoundTag tag)
{
	bool isPlaying = false;
	for (auto it = m_instances.begin(); it != m_instances.end(); it++)
	{
		if (it->tag == tag)
		{
			isPlaying |= m_manager->IsPlaying(it->id);
		}
	}
	return isPlaying;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::StopData(SoundData* soundData)
{
	for (auto it = m_instances.begin(); it != m_instances.end(); it++)
	{
		if (it->data == soundData)
		{
			m_manager->Stop(it->id);
		}
	}
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void SoundImplemented::Calculate3DSound(const ::Effekseer::Vector3D& position, float rolloffDistance, float& rolloff, float& pan)
{
	using Vector3D = ::Effekseer::Vector3D;

	Vector3D diff = position - m_listener.position;
	float distance = Vector3D::Length(diff);

	if (distance == 0.0f)
	{
		rolloff = 1.0f;
		pan = 0.0f;
		return;
	}

	// Calculate rolloff
	if (distance <= rolloffDistance)
	{
		rolloff = 1.0f;
	}
	else if (distance >= rolloffDistance)
	{
		rolloff = 0.0f;
	}
	{
		rolloff = (1.0f - (distance - rolloffDistance) / rolloffDistance);
	}

	// Calculate pan
	Vector3D relativeVector = diff * (1.0f / distance);
	pan = Vector3D::Dot(relativeVector, m_listener.rightVector);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
} // namespace EffekseerSound
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
