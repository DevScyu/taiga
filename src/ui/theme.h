/*
** Taiga
** Copyright (C) 2010-2018, Eren Okka
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>
#include <vector>

#include <windows/win/common_controls.h>
#include <windows/win/gdi.h>

namespace ui {

enum Icons16px {
  kIcon16_Green,
  kIcon16_Blue,
  kIcon16_Red,
  kIcon16_Gray,
  kIcon16_Play,
  kIcon16_Search,
  kIcon16_Folder,
  kIcon16_AppBlue,
  kIcon16_AppGray,
  kIcon16_Refresh,
  kIcon16_Download,
  kIcon16_Settings,
  kIcon16_Cross,
  kIcon16_Plus,
  kIcon16_Minus,
  kIcon16_ArrowUp,
  kIcon16_ArrowDown,
  kIcon16_Funnel,
  kIcon16_FunnelCross,
  kIcon16_FunnelTick,
  kIcon16_FunnelPlus,
  kIcon16_FunnelPencil,
  kIcon16_Calendar,
  kIcon16_Category,
  kIcon16_Sort,
  kIcon16_Balloon,
  kIcon16_Clock,
  kIcon16_Home,
  kIcon16_DocumentA,
  kIcon16_Chart,
  kIcon16_Feed,
  kIcon16_Details,
  kIcon16_Import,
  kIcon16_Export,
  kIconCount16px
};

enum Icons24px {
  kIcon24_Sync,
  kIcon24_Folders,
  kIcon24_Tools,
  kIcon24_Settings,
  kIcon24_About,
  kIcon24_Globe,
  kIcon24_Library,
  kIcon24_Application,
  kIcon24_Recognition,
  kIcon24_Sharing,
  kIcon24_Feed,
  kIconCount24px
};

enum ListProgressType {
  kListProgressAired,
  kListProgressAvailable,
  kListProgressBackground,
  kListProgressBorder,
  kListProgressButton,
  kListProgressCompleted,
  kListProgressDropped,
  kListProgressOnHold,
  kListProgressPlanToWatch,
  kListProgressSeparator,
  kListProgressWatching
};

enum ListGlobalType {
  kListGlobalDarkBlue,
  kListGlobalGray,
  kListGlobalLightBlue,
  kListGlobalLightGray,
  kListGlobalLightGreen,
  kListGlobalLightRed,
  kListGlobalMainInstruction,
};

const COLORREF kColorDarkBlue = ui::Theme.GetListGlobalColor(kListGlobalDarkBlue);
const COLORREF kColorGray = ui::Theme.GetListGlobalColor(kListGlobalGray);
const COLORREF kColorLightBlue = ui::Theme.GetListGlobalColor(kListGlobalLightBlue);
const COLORREF kColorLightGray = ui::Theme.GetListGlobalColor(kListGlobalLightGray); //f8f8f8
const COLORREF kColorLightGreen = ui::Theme.GetListGlobalColor(kListGlobalLightGreen); //e1f5e7
const COLORREF kColorLightRed = ui::Theme.GetListGlobalColor(kListGlobalLightRed); //f5e1e7
const COLORREF kColorMainInstruction = ui::Theme.GetListGlobalColor(kListGlobalMainInstruction); //003399

class ThemeManager {
public:
  ThemeManager();
  ~ThemeManager() {}

  bool Load();

  void CreateBrushes();
  void CreateFonts(HDC hdc);
  HBRUSH GetBackgroundBrush() const;
  HFONT GetBoldFont() const;
  HFONT GetHeaderFont() const;

  win::ImageList& GetImageList16();
  win::ImageList& GetImageList24();

  void DrawListProgress(HDC hdc, const LPRECT rect, ListProgressType type);
  COLORREF GetListProgressColor(ListProgressType type);

private:
  win::Brush brush_background_;

  win::Font font_bold_;
  win::Font font_header_;

  win::ImageList icons16_;
  win::ImageList icons24_;

  struct Progress {
    COLORREF value[3];
    std::wstring type;
  };
  std::map<ListProgressType, Progress> list_progress_;
};

extern ThemeManager Theme;

}  // namespace ui
