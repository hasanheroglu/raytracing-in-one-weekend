#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "rtweekend.h"
#include "material.h"
#include "hittable.h"

class lambertian : public material {
    public:
        lambertian(const color &a) : albedo(a) {}

        virtual bool scatter(
            const ray &r_in, hit_record &rec, color &attenuation, ray &scattered
        ) const override {
            auto scatter_direction = rec.normal + random_unit_vector();

            if (scatter_direction.near_zero()) {
                scatter_direction = rec.normal;
            }

            scattered = ray(rec.p, scatter_direction);
            attenuation = albedo;
            return true;
        }

    public:
        color albedo;
};

#endif