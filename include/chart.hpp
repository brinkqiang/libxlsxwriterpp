//  :copyright: (c) 2017 Alex Huszagh.
//  :license: FreeBSD, see LICENSE.md for more details.
/**
 *  C++ bindings for libxlsxwriter charts.
 */

#pragma once

#include "common.hpp"

#include <string>
#include <xlsxwriter/chart.h>


namespace xlsxwriter
{
// ENUMS
// -----


enum class ChartType: uint8_t
{
    NONE = 0,
    AREA,
    AREA_STACKED,
    AREA_STACKED_PERCENT,
    BAR,
    BAR_STACKED,
    BAR_STACKED_PERCENT,
    COLUMN,
    COLUMN_STACKED,
    COLUMN_STACKED_PERCENT,
    DOUGHNUT,
    LINE,
    PIE,
    SCATTER,
    SCATTER_STRAIGHT,
    SCATTER_STRAIGHT_WITH_MARKERS,
    SCATTER_SMOOTH,
    SCATTER_SMOOTH_WITH_MARKERS,
    RADAR,
    RADAR_WITH_MARKERS,
    RADAR_FILLED,
};


enum class MarkerType: uint8_t
{
    AUTOMATIC = 0,
    NONE,
    SQUARE,
    DIAMOND,
    TRIANGLE,
    X,
    STAR,
    SHORT_DASH,
    LONG_DASH,
    CIRCLE,
    PLUS,
};


enum class LabelSeparators: uint8_t
{
    COMMA = 0,
    SEMICOLON,
    PERIOD,
    NEWLINE,
    SPACE,
};


enum class ChartLabelPosition: uint8_t
{
    DEFAULT = 0,
    CENTER,
    RIGHT,
    LEFT,
    ABOVE,
    BELOW,
    INSIDE_BASE,
    INSIDE_END,
    OUTSIDE_END,
    BEST_FIT,
};


enum class TrendlineType: uint8_t
{
    LINEAR = 0,
    LOG,
    POLY,
    POWER,
    EXP,
    AVERAGE,
};


enum class ErrorBarType: uint8_t
{
    STD_ERROR = 0,
    FIXED,
    PERCENTAGE,
    STD_DEV,
};


enum class ErrorBarDirection: uint8_t
{
    BOTH = 0,
    PLUS,
    MINUS,
};


enum class ErrorBarCap: uint8_t
{
    END_CAP = 0,
    NO_CAP,
};


enum class LegendPosition: uint8_t
{
    NONE = 0,
    RIGHT,
    LEFT,
    TOP,
    BOTTOM,
    OVERLAY_RIGHT,
    OVERLAY_LEFT,
};


enum class ChartBlank: uint8_t
{
    AS_GAP = 0,
    AS_ZERO,
    AS_CONNECTED,
};


enum class ChartAxisPosition: uint8_t
{
    DEFAULT = 0,
    ON_TICK,
};


enum class ChartAxisLabelPosition: uint8_t
{
    NEXT_TO = 0,
    HIGH,
    LOW,
    NONE,
};


enum class TickMark: uint8_t
{
    DEFAULT = 0,
    NONE,
    INSIDE,
    OUTSIDE,
    CROSSING,
};


enum class DisplayUnits: uint8_t
{
    NONE = 0,
    HUNDREDS,
    THOUSANDS,
    TEN_THOUSANDS,
    HUNDRED_THOUSANDS,
    MILLIONS,
    TEN_MILLIONS,
    HUNDRED_MILLIONS,
    BILLIONS,
    TRILLIONS,
};

// OBJECTS
// -------


typedef lxw_chart_line ChartLine;
typedef lxw_chart_fill ChartFill;
typedef lxw_chart_pattern ChartPattern;
typedef lxw_chart_font ChartFont;
typedef lxw_chart_point ChartPoint;
typedef std::vector<ChartPoint> ChartPoints;
typedef std::vector<uint16_t> Series;


class ChartSeries
{
protected:
    lxw_chart_series *ptr = nullptr;

    friend class Chart;

    ChartSeries(lxw_chart_series *ptr);

public:
    ChartSeries() = default;
    ChartSeries(const ChartSeries&) = default;
    ChartSeries & operator=(const ChartSeries&) = default;
    ChartSeries(ChartSeries &&other) = default;
    ChartSeries & operator=(ChartSeries &&other) = default;

    // DATA
    void set_categories(const std::string &sheetname,
        const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void set_values(const std::string &sheetname,
        const Row first_row,
        const Column first_col,
        const Row last_row,
        const Column last_col);
    void set_name(const std::string &name);
    void set_name_range(const std::string &name,
        const Row row,
        const Column col);
    void set_line(const ChartLine &line);
    void set_fill(const ChartFill &fill);
    void invert_if_negative();
    void set_pattern(const ChartPattern &pattern);
    void set_marker_type(const MarkerType type);
    void set_marker_size(const uint8_t size);
    void set_marker_line(const ChartLine &line);
    void set_marker_fill(const ChartFill &fill);
    void set_marker_pattern(const ChartPattern &pattern);
    void set_points(const ChartPoints &points);
    void set_smooth(const bool smooth);
    void set_labels();
    void set_labels_options(const bool show_name,
        const bool show_category,
        const bool show_value);
    void set_labels_separator(const LabelSeparators separator);
    void set_labels_position(const ChartLabelPosition position);
    void set_labels_leader_line();
    void set_labels_legend();
    void set_labels_percentage();
    void set_labels_num_format(const std::string &num_format);
    void set_labels_font(const ChartFont &font);
    void set_trendline(const TrendlineType type,
        const uint8_t value);
    void set_trendline_forecast(const double forward,
        const double backward);
    void set_trendline_equation();
    void set_trendline_r_squared();
    void set_trendline_intercept(const double intercept);
    void set_trendline_name(const std::string &name);
    void set_trendline_line(const ChartLine &line);
};


class ErrorBars
{
protected:
    lxw_series_error_bars *ptr = nullptr;

    friend class Chart;

    ErrorBars(lxw_series_error_bars *ptr);

public:
    ErrorBars() = default;
    ErrorBars(const ErrorBars&) = default;
    ErrorBars & operator=(const ErrorBars&) = default;
    ErrorBars(ErrorBars &&other) = default;
    ErrorBars & operator=(ErrorBars &&other) = default;

    void set_error_bars(const ErrorBarType type,
        const double value);
    void set_error_bars_direction(const ErrorBarDirection direction);
    void set_error_bars_endcap(const ErrorBarCap endcap);
    void set_error_bars_line(const ChartLine &line);
};


class ChartAxis
{
protected:
    lxw_chart_axis *ptr = nullptr;

    friend class Chart;

    ChartAxis(lxw_chart_axis *ptr);

public:
    ChartAxis() = default;
    ChartAxis(const ChartAxis&) = default;
    ChartAxis & operator=(const ChartAxis&) = default;
    ChartAxis(ChartAxis &&other) = default;
    ChartAxis & operator=(ChartAxis &&other) = default;

    void set_name(const std::string &name);
    void set_name_range(const std::string &name,
        const Row row,
        const Column col);
    void set_name_font(const ChartFont &font);
    void set_num_font(const ChartFont &font);
    void set_num_format(const std::string &num_format);
    void set_line(const ChartLine &line);
    void set_fill(const ChartFill &fill);
    void set_pattern(const ChartPattern &pattern);
    void set_reverse();
    void set_crossing(const double value);
    void set_crossing_max();
    void axis_off();
    void set_position(const ChartAxisPosition position);
    void set_label_position(const ChartAxisLabelPosition position);
    void set_min(const double min);
    void set_max(const double max);
    void set_log_base(const uint16_t log_base);
    void set_major_tick_mark(const TickMark type);
    void set_minor_tick_mark(const TickMark type);
    void set_interval_unit(const uint16_t unit);
    void set_interval_tick(const uint16_t unit);
    void set_major_unit(const double unit);
    void set_minor_unit(const double unit);
    void set_display_units(const DisplayUnits units);
    void set_display_units_visible(const bool visible);
    void major_gridlines_set_visible(const bool visible);
    void minor_gridlines_set_visible(const bool visible);
    void major_gridlines_set_line(const ChartLine &line);
    void minor_gridlines_set_line(const ChartLine &line);

};


class Chart
{
protected:
    lxw_chart *ptr = nullptr;
    friend class Workbook;
    friend class Worksheet;

    Chart(lxw_chart *ptr);

public:
    Chart() = default;
    Chart(const Chart&) = default;
    Chart & operator=(const Chart&) = default;
    Chart(Chart &&other) = default;
    Chart & operator=(Chart &&other) = default;

    // DATA
    ChartSeries add_series(const std::string &categories,
        const std::string &values);
    ChartAxis x_axis();
    ChartAxis y_axis();

    void set_name(const std::string &name);
    void set_name_range(const std::string &name,
        const Row row,
        const Column col);
    void set_name_font(const ChartFont &font);
    void title_off();
    void set_legend_position(const LegendPosition position);
    void set_legend_font(const ChartFont &font);
    void delete_legend_series(const Series &series);
    void set_chartarea_line(const ChartLine &line);
    void set_chartarea_fill(const ChartFill &fill);
    void set_chartarea_pattern(const ChartPattern &pattern);
    void set_plotarea_line(const ChartLine &line);
    void set_plotarea_fill(const ChartFill &fill);
    void set_plotarea_pattern(const ChartPattern &pattern);
    void set_style(const uint8_t style);
    void set_table();
    void set_table_grid(const bool horizontal,
        const bool vertical,
        const bool outline,
        const bool legend_keys);
    void set_table_font(const ChartFont &font);
    void set_up_down_bars();
    void set_up_down_bars_format(const ChartLine &up_bar_line,
        const ChartFill &up_bar_fill,
        const ChartLine &down_bar_line,
        const ChartFill &down_bar_fill);
    void set_drop_lines(const ChartLine &line);
    void set_high_low_lines(const ChartLine &line);
    void set_series_overlap(const uint8_t overlap);
    void set_series_gap(const uint16_t gap);
    void show_blanks_as(const ChartBlank option);
    void show_hidden_data();
    void set_rotation(const uint16_t rotation);
    void set_hole_size(const uint8_t size);
};

}   /* xlsxwriter */
