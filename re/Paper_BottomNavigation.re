[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "BottomNavigation";

[@bs.deriving abstract]
type route = {
  key: string,
  [@bs.optional]
  title: string,
  [@bs.optional]
  icon: ReasonReact.reactElement,
  [@bs.optional]
  color: string,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  testID: string,
};

[@bs.deriving abstract]
type navigationState = {
  index: int,
  routes: array(route),
};

type renderSceneType = {
  route,
  jumpTo: string => unit,
};

type renderIconType = {
  route,
  focused: bool,
  color: string,
};

type routeType = {route};

[@bs.deriving abstract]
type props = {
  navigationState,
  onIndexChange: int => unit,
  renderScene: renderSceneType => ReasonReact.reactElement,
  [@bs.optional]
  renderIcon: renderIconType => ReasonReact.reactElement,
  [@bs.optional]
  getLabelText: routeType => string,
  [@bs.optional]
  getAccessibilityLabel: routeType => string,
  [@bs.optional]
  getTestID: routeType => string,
  [@bs.optional]
  getColor: routeType => string,
  [@bs.optional]
  onTabPress: routeType => string,
  [@bs.optional]
  activeColor: string,
  [@bs.optional]
  inactiveColor: string,
  [@bs.optional]
  barStyle: BsReactNative.Style.t,
  [@bs.optional]
  shifting: bool,
  [@bs.optional]
  labeled: bool,
  [@bs.optional]
  style: BsReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make =
    (
      ~shifting=?,
      ~labeled=?,
      ~navigationState,
      ~onIndexChange,
      ~renderScene,
      ~renderIcon=?,
      ~getLabelText=?,
      ~getAccessibilityLabel=?,
      ~getTestID=?,
      ~getColor=?,
      ~onTabPress=?,
      ~activeColor=?,
      ~inactiveColor=?,
      ~barStyle=?,
      ~style=?,
      ~theme=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~shifting?,
        ~labeled?,
        ~navigationState,
        ~onIndexChange,
        ~renderScene,
        ~renderIcon?,
        ~getLabelText?,
        ~getAccessibilityLabel?,
        ~getTestID?,
        ~getColor?,
        ~onTabPress?,
        ~activeColor?,
        ~inactiveColor?,
        ~barStyle?,
        ~style?,
        ~theme?,
        (),
      ),
    children,
  );
