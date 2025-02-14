
#ifndef MINDIFIL_H
#define MINDIFIL_H

#include <stdint.h>

#include "mindievt.h"

/**
 * \file mindifil.h
 * \brief Functions, constants, and macros for dealing with MIDI files.
 */

/**
 * \addtogroup midi_file_header MIDI File Header
 * \{
 */

/*! \brief Offset in bytes of the MIDI header size in the MIDI header. */
#define MINDI_HEADER_SZ_OFFSET 4

/*! \brief Offset in bytes of the MIDI format in the MIDI header. */
#define MINDI_HEADER_FMT_OFFSET 8

/*! \brief Offset in bytes of the number of tracks in the MIDI header. */
#define MINDI_HEADER_TRACKS_OFFSET 10

/*! \brief Offset in bytes of the time divisions in the MIDI header. */
#define MINDI_HEADER_TDIV_OFFSET 12

/*! \} */

#define MINDI_CHUNK_SZ_OFFSET 4

#define MINDI_CHUNK_HEADER_SZ 8

/*! \brief Return the FULL size of the MIDI header. */
#define mindi_header_sz( bytes ) (MINDI_HEADER_SZ_OFFSET + sizeof( uint32_t ) + (mindi_endian_swap_32( *((uint32_t*)(&bytes[MINDI_HEADER_SZ_OFFSET])))))

/*! \brief Return The MIDI format (0, 1, or 2). */
#define mindi_header_format( bytes ) ((mindi_endian_swap_16( *((uint16_t*)(&bytes[MINDI_HEADER_FMT_OFFSET])))) & 0xffff)

/*! \brief Return the number of tracks in the MIDI file. */
#define mindi_header_tracks( bytes ) ((mindi_endian_swap_16( *((uint16_t*)(&bytes[MINDI_HEADER_TRACKS_OFFSET])))) & 0xffff)

#define mindi_chunk_sz( bytes, offset ) (MINDI_CHUNK_SZ_OFFSET + sizeof( uint32_t ) + (mindi_endian_swap_32( *((uint32_t*)(&bytes[offset + MINDI_CHUNK_SZ_OFFSET])))))

/**
 * \brief Get the offset of the next chunk, given the offset of an existing
 *        chunk, or the offset of the first chunk of the previous offset is 0.
 */
int32_t mindi_next_chunk(
   uint8_t* midi_bytes, uint32_t midi_bytes_sz, uint32_t offset );

int32_t mindi_next_event(
   uint8_t* midi_bytes, uint32_t midi_bytes_sz, uint32_t offset, uint8_t prev );

#endif /* !MINDIFIL_H */

