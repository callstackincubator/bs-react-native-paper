open BsReactNative;
open Navigation;

module Styles = {
  open Style;

  let listItem = style([padding(Pt(10.))]);

  let listItemText = style([fontSize(Float(16.))]);
};

type screen = {
  id: int,
  name: string,
  route: Config.route,
};

type examples = array(screen);

let examples = [|
  {id: 1, name: "Button Example", route: Config.ButtonExample},
  {id: 2, name: "Card Example", route: Config.CardExample},
  {id: 3, name: "Chip Example", route: Config.ChipExample},
  {id: 4, name: "Checkbox Example", route: Config.CheckboxExample},
  {id: 5, name: "Dialog Example", route: Config.DialogExample},
  {id: 6, name: "Divider Example", route: Config.DividerExample},
  {id: 7, name: "FAB Example", route: Config.FABExample},
  {id: 8, name: "IconButton Example", route: Config.IconButtonExample},
  {id: 9, name: "ListAccordion Example", route: Config.ListAccordionExample},
  {id: 10, name: "ListSection Example", route: Config.ListSectionExample},
  {id: 11, name: "ProgressBar Example", route: Config.ProgressBarExample},
  {id: 12, name: "RadioButton Example", route: Config.RadioButtonExample},
  {id: 13, name: "Searchbar Example", route: Config.SearchbarExample},
  {id: 14, name: "Snackbar Example", route: Config.SnackbarExample},
  {id: 15, name: "Surface Example", route: Config.SurfaceExample},
  {id: 16, name: "Switch Example", route: Config.SwitchExample},
  {id: 17, name: "TextInput Example", route: Config.TextInputExample},
  {
    id: 18,
    name: "TouchableRipple Example",
    route: Config.TouchableRippleExample,
  },
  {id: 19, name: "Typography Example", route: Config.TypographyExample},
|];

let keyExtractor = (item, _index) => string_of_int(item.id);

let renderItem = (navigation: StackNavigator.navigation) =>
  FlatList.renderItem((screen: FlatList.renderBag(screen)) =>
    <Paper.List.Item
      title={screen.item.name}
      style=Styles.listItem
      onPress={
        _event =>
          Js.Global.setTimeout(() => navigation.push(screen.item.route), 0)
          |> ignore
      }
    />
  );

let component = ReasonReact.statelessComponent("Home");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Example App" navigation>
      ...{
           () =>
             <View>
               <FlatList
                 data=examples
                 keyExtractor
                 renderItem={renderItem(navigation)}
                 itemSeparatorComponent={
                   FlatList.separatorComponent(
                     (_props: FlatList.separatorProps(screen)) =>
                     <Paper.Divider />
                   )
                 }
               />
             </View>
         }
    </StackNavigator.Screen>,
};
