type jsIconType('a) =
  | String: jsIconType(string)
  | Element: jsIconType(Icon.renderIcon);

[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~mode: string=?,
    ~disabled: bool=?,
    ~compact: bool=?,
    ~raised: bool=?,
    ~loading: bool=?,
    ~dark: bool=?,
    ~icon: 'a=?,
    ~color: string=?,
    ~accessibilityLabel: string=?,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~onPress: ReactNative.Event.pressEvent => unit=?,
    ~children: React.element
  ) =>
  React.element =
  "Button";

[@bs.deriving jsConverter]
type modes = [
  | [@bs.as "text"] `text
  | [@bs.as "outlined"] `outlined
  | [@bs.as "contained"] `contained
];

let makeProps = (~mode=?, ~icon: option((jsIconType('a), 'a))=?) => {
  makeProps(
    ~mode=?Belt.Option.map(mode, modesToJs),
    ~icon=?Belt.Option.map(icon, ((_, value)) => value),
  );
};
