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
#include "lowlevel/Music.h"
#include "lowlevel/SpcDecoder.h"
#include "lowlevel/FileTools.h"
#include "lowlevel/Debug.h"
#include "lowlevel/StringConcat.h"
#include <vector>

const std::string Music::none = "none";
const std::string Music::unchanged = "same";

/**
 * \brief Lua name of each music format.
 */
const std::string Music::format_names[] = {
  "",
  "spc",
  "it",
  "ogg",
  ""  // Sentinel.
};

/**
 * \brief Creates a new music.
 * \param music_id id of the music (file name without extension)
 */
Music::Music(const std::string& music_id) {
    return;
}

/**
 * \brief Destroys the music.
 */
Music::~Music() {
    return;
}

/**
 * \brief Initializes the music system.
 */
void Music::initialize() {

}

/**
 * \brief Exits the music system.
 */
void Music::quit() {

}

/**
 * \brief Returns whether the music system is initialized.
 * \return true if the music system is initilialized
 */
bool Music::is_initialized() {
  return false;
}

/**
 * \brief Returns the format of the current music.
 * \return The format of the current music.
 */
Music::Format Music::get_format() {
    return NO_FORMAT;
}

/**
 * \brief Returns the current volume of music.
 * \return the volume (0 to 100)
 */
int Music::get_volume() {

  return 0;
}

/**
 * \brief Sets the volume of musics.
 * \param volume the new volume (0 to 100)
 */
void Music::set_volume(int volume) {

}

/**
 * \brief Returns the number of channels of the current music.
 *
 * This function is only supported for .it musics.
 *
 * \return The number of channels.
 */
int Music::get_num_channels() {

  Debug::check_assertion(get_format() == IT,
      "This function is only supported for .it musics");

  return 0;
}

/**
 * \brief Returns the volume of a channel of the current music.
 *
 * This function is only supported for .it musics.
 *
 * \param channel Index of a channel.
 * \return The volume of this channel.
 */
int Music::get_channel_volume(int channel) {

  return 0;
}

/**
 * \brief Sets the volume of a channel of the current music.
 *
 * This function is only supported for .it musics.
 *
 * \param channel Index of a channel.
 * \param volume The volume to set.
 */
void Music::set_channel_volume(int channel, int volume) {

  Debug::check_assertion(get_format() == IT,
      "This function is only supported for .it musics");

}

/**
 * \brief Returns the tempo of the current music.
 *
 * This function is only supported for .it musics.
 *
 * \return The tempo of the current music.
 */
int Music::get_tempo() {

  Debug::check_assertion(get_format() == IT,
      "This function is only supported for .it musics");

  return 0;
}

/**
 * \brief Sets the tempo of the current music.
 *
 * This function is only supported for .it musics.
 *
 * \param tempo The tempo to set.
 */
void Music::set_tempo(int tempo) {

  Debug::check_assertion(get_format() == IT,
      "This function is only supported for .it musics");
}


/**
 * \brief Returns the music currently playing.
 * \return the current music, or NULL if no music is being played
 */
Music* Music::get_current_music() {
  return NULL;
}

/**
 * \brief Returns the id of the music currently playing.
 * \return the id of the current music, or "none" if no music is being played
 */
const std::string& Music::get_current_music_id() {
  return none;
}

/**
 * \brief Tries to find a music file from a music id.
 * \param music_id Id of the music to find (file name without
 * directory or extension). Cannot be Music::none or Music::unchanged.
 * \param file_name Resulting file name with its extension
 * (empty string if not found).
 * \param format Resulting music format.
 */
void Music::find_music_file(const std::string& music_id,
    std::string& file_name, Format& format) {

  file_name = "";
  format = OGG;

  std::string file_name_start = std::string("musics/" + music_id);
  if (FileTools::data_file_exists(file_name_start + ".ogg")) {
    format = OGG;
    file_name = file_name_start + ".ogg";
  }
  else if (FileTools::data_file_exists(file_name_start + ".it")) {
    format = IT;
    file_name = file_name_start + ".it";
  }
  else if (FileTools::data_file_exists(file_name_start + ".spc")) {
    format = SPC;
    file_name = file_name_start + ".spc";
  }
}

/**
 * \brief Returns whether a music exists.
 * \param music_id Id of the music to test. Music::none and Music::unchanged
 * are also considered valid.
 * \return true If this music exists.
 */
bool Music::exists(const std::string& music_id) {

  if (music_id == none || music_id == unchanged) {
    return true;
  }

  std::string file_name;
  Format format;
  find_music_file(music_id, file_name, format);

  return !file_name.empty();
}

/**
 * \brief Plays a music.
 *
 * If the music is different from the current one,
 * the current one is stopped.
 * The music specified can also be Music::none_id (then the current music is just stopped)
 * or even Music::unchanged_id (nothing is done in this case).
 *
 * \param music_id id of the music to play (file name without extension)
 */
void Music::play(const std::string& music_id) {

}

/**
 * \brief Updates the music system.
 *
 * When a music is playing, this function makes it update.
 */
void Music::update() {
    return;
}
