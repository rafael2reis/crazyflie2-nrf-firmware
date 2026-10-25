#pragma once
/* Crazyflie BLE uplink validation. SPDX-License-Identifier: LGPL-3.0-or-later */
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint8_t data[32];
  uint8_t length;
  uint8_t index;
  uint8_t pid;
  bool active;
} BleCrtpupState;

void bleCrtpupReset(BleCrtpupState *state);
/* Returns true only on complete packet; invalid input discards partial state. */
bool bleCrtpupConsume(BleCrtpupState *state, const uint8_t *fragment, uint16_t size);
