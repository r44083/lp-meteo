#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "sd.hpp"
#include "gpio/gpio.hpp"
#include "spi/spi.hpp"

namespace drv
{
class sd_spi : public sd
{
	public:
		sd_spi(hal::spi &spi, hal::gpio &cs, hal::gpio *cd = NULL);
		~sd_spi();
	
	private:
		void select(bool is_selected) override;
		int8_t init_sd() override;
		void set_speed(uint32_t speed) override;
		int8_t send_cmd(cmd_t cmd, uint32_t arg, resp_t resp_type,
			uint8_t *resp) override;
		int8_t read_data(void *data, uint16_t size) override;
		int8_t write_data(void *data, uint16_t size) override;
		
		int8_t wait_ready();
		
		hal::spi &_spi;
		hal::gpio &_cs;
};
}
