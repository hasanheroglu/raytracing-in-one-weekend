#ifndef METAL_H
#define METAL_H

#include "rtweekend.h"
#include "material.h"
#include "hittable.h"

class metal: public material {
    public:
        metal(const color &a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

        virtual bool scatter (
            const ray &r_in, hit_record &rec, color &attenuation, ray &scattered
        ) const override {
            auto reflected = reflect(unit_vector(r_in.direction()), rec.normal);
            scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere());
            attenuation = albedo;
            return (dot(scattered.direction(), rec.normal) > 0);
        }

    public:
        color albedo;
        double fuzz;
};

#endif