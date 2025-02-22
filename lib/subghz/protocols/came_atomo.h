#pragma once
#include "base.h"

#define SUBGHZ_PROTOCOL_CAME_ATOMO_NAME "CAME Atomo"

typedef struct SubGhzProtocolDecoderCameAtomo SubGhzProtocolDecoderCameAtomo;
typedef struct SubGhzProtocolEncoderCameAtomo SubGhzProtocolEncoderCameAtomo;

extern const SubGhzProtocolDecoder subghz_protocol_came_atomo_decoder;
extern const SubGhzProtocolEncoder subghz_protocol_came_atomo_encoder;
extern const SubGhzProtocol subghz_protocol_came_atomo;

/**
 * Allocate SubGhzProtocolDecoderCameAtomo.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolDecoderCameAtomo* pointer to a SubGhzProtocolDecoderCameAtomo instance
 */
void* subghz_protocol_decoder_came_atomo_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolDecoderCameAtomo.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 */
void subghz_protocol_decoder_came_atomo_free(void* context);

/**
 * Reset decoder SubGhzProtocolDecoderCameAtomo.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 */
void subghz_protocol_decoder_came_atomo_reset(void* context);

/**
 * Parse a raw sequence of levels and durations received from the air.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 * @param level Signal level true-high false-low
 * @param duration Duration of this level in, us
 */
void subghz_protocol_decoder_came_atomo_feed(void* context, bool level, uint32_t duration);

/**
 * Getting the hash sum of the last randomly received parcel.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 * @return hash Hash sum
 */
uint8_t subghz_protocol_decoder_came_atomo_get_hash_data(void* context);

/**
 * Serialize data SubGhzProtocolDecoderCameAtomo.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param preset The modulation on which the signal was received, SubGhzPesetDefinition
 * @return true On success
 */
bool subghz_protocol_decoder_came_atomo_serialize(
    void* context,
    FlipperFormat* flipper_format,
    SubGhzPesetDefinition* preset);

/**
 * Deserialize data SubGhzProtocolDecoderCameAtomo.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return true On success
 */
bool subghz_protocol_decoder_came_atomo_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Getting a textual representation of the received data.
 * @param context Pointer to a SubGhzProtocolDecoderCameAtomo instance
 * @param output Resulting text
 */
void subghz_protocol_decoder_came_atomo_get_string(void* context, string_t output);
