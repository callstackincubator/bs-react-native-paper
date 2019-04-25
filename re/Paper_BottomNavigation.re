[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "BottomNavigation";

[@bs.deriving abstract]
type _route = {
  key: string,
  [@bs.optional]
  title: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  color: string,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  testID: string,
};

let route =
    (~key, ~title=?, ~icon=?, ~color=?, ~accessibilityLabel=?, ~testID=?, ()) =>
  switch (icon) {
  | Some(Icon.Name(name)) =>
    _route(
      ~key,
      ~title?,
      ~iconAsString=name,
      ~color?,
      ~accessibilityLabel?,
      ~testID?,
      (),
    )
  | Some(Icon.Element(renderFunc)) =>
    _route(
      ~key,
      ~title?,
      ~iconAsRenderFunc=renderFunc,
      ~color?,
      ~accessibilityLabel?,
      ~testID?,
      (),
    )
  | None => _route(~key, ~title?, ~color?, ~accessibilityLabel?, ~testID?, ())
  };

[@bs.deriving abstract]
type createNavigationState = {
  index: int,
  routes: array(_route),
};

type renderIconType = {
  route: _route,
  focused: bool,
  color: string,
};

type routeType = {route: _route};

type routeProps = {
  key: string,
  title: string,
  color: string,
};

type jsRenderSceneProps = {
  .
  "route": routeProps,
  "jumpTo": string => unit,
};

type renderSceneProps = {
  route: routeProps,
  jumpTo: string => unit,
};

type renderSceneType = jsRenderSceneProps => ReasonReact.reactElement;

let renderSceneType =
    (reRenderScene: renderSceneProps => ReasonReact.reactElement)
    : renderSceneType =>
  (jsRouteProps: jsRenderSceneProps) =>
    reRenderScene({route: jsRouteProps##route, jumpTo: jsRouteProps##jumpTo});

[@bs.deriving abstract]
type props = {
  navigationState: createNavigationState,
  onIndexChange: int => unit,
  renderScene: renderSceneType,
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
  barStyle: ReactNative.Style.t,
  [@bs.optional]
  shifting: bool,
  [@bs.optional]
  labeled: bool,
  [@bs.optional]
  style: ReactNative.Style.t,
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
