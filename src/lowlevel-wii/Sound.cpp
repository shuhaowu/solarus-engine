/*
 * Copyright (C) 2006-2013 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <cstring>  // memcpy
#include <cmath>
#include <sstream>
#include <vector>
#include "lowlevel/Sound.h"
#include "lowlevel/Music.h"
#include "lowlevel/FileTools.h"
#include "lowlevel/Debug.h"
#include "lowlevel/StringConcat.h"
#include "QuestResourceList.h"

/**
 * \brief Creates a new Ogg Vorbis sound.
 * \param sound_id id of the sound: name of a .ogg file in the sounds subdirectory,
 * without the extension (.ogg is added automatically)
 */
Sound::Sound(const std::string& sound_id) {

}

/**
 * \brief Destroys the sound.
 */
Sound::~Sound() {

}

/**
 * \brief Initializes the audio (music and sound) system.
 *
 * This method should be called when the application starts.
 * If the argument -no-audio is provided, this function has no effect and
 * there will be no sound.
 *
 * \param argc command-line arguments number
 * \param argv command-line arguments
 */
void Sound::initialize(int argc, char** argv) {

}

/**
 * \brief Closes the audio (music and sound) system.
 *
 * This method should be called when exiting the application.
 */
void Sound::quit() {

}

/**
 * \brief Returns whether the audio (music and sound) system is initialized.
 * \return true if the audio (music and sound) system is initilialized
 */
bool Sound::is_initialized() {
  return false;
}

/**
 * \brief Loads and decodes all sounds listed in the game database.
 */
void Sound::load_all() {

}

/**
 * \brief Returns whether a sound exists.
 * \param sound_id id of the sound to test
 * \return true if the sound exists
 */
bool Sound::exists(const std::string& sound_id) {

  std::ostringstream oss;
  oss << "sounds/" << sound_id << ".ogg";
  return FileTools::data_file_exists(oss.str());
}

/**
 * \brief Starts playing the specified sound.
 * \param sound_id id of the sound to play
 */
void Sound::play(const std::string& sound_id) {

}

/**
 * \brief Returns the current volume of sound effects.
 * \return the volume (0 to 100)
 */
int Sound::get_volume() {

  return 0;
}

/**
 * \brief Sets the volume of sound effects.
 * \param volume the new volume (0 to 100)
 */
void Sound::set_volume(int volume) {

}

/**
 * \brief Updates the audio (music and sound) system.
 *
 * This function is called repeatedly by the game.
 */
void Sound::update() {

}

/**
 * \brief Loads and decodes the sound into memory.
 */
void Sound::load() {

}

/**
 * \brief Plays the sound.
 * \return true if the sound was loaded successfully, false otherwise
 */
bool Sound::start() {
  return false;
}

