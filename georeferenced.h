#ifndef GEOREFERENCED_H
#define GEOREFERENCED_H

#include <QPointF>
#include <QGeoCoordinate>
class GDALDataset;
class OGRCoordinateTransformation;

class Georeferenced
{
public:
    Georeferenced();
    QPointF pixelToProjectedPoint(QPointF const &point) const;
    QPointF projectedPointToPixel(QPointF const &point) const;
    QPointF project(QGeoCoordinate const &point) const;
    QGeoCoordinate unproject(QPointF const &point) const;
    QPointF geoToPixel(QGeoCoordinate const &point) const;
    QGeoCoordinate pixelToGeo(QPointF const &point) const;
    QString const &projection() const;
protected:
    void extractGeoreference(GDALDataset *dataset);
private:
    double geoTransform[6];
    double inverseGeoTransform[6];
    OGRCoordinateTransformation *projectTransformation,*unprojectTransformation;
    QString m_projection;
};

#endif // GEOREFERENCED_H
